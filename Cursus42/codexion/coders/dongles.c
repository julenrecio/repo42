/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:19:44 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/16 12:20:13 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	handle_cooldown(t_dongle *dongle)
{
	struct timespec	deadline;

	if (get_current_time() < dongle->cooldown_at)
	{
		deadline.tv_sec = dongle->cooldown_at / 1000;
		deadline.tv_nsec = (dongle->cooldown_at % 1000) * 1000000;
		pthread_cond_timedwait(&dongle->cond, &dongle->mutex,
			&deadline);
	}
	else
	{
		dongle->available = true;
		dongle->cooldown_at = 0;
		dongle->cooling_down = false;
		pthread_cond_broadcast(&dongle->cond);
	}
}

static void	remove_request(t_request **queue, t_request *target)
{
	t_request	**curr;

	curr = queue;
	while (*curr && *curr != target)
		curr = &(*curr)->next;
	if (*curr == target)
		*curr = target->next;
}

bool	adquire_dongle(t_dongle *dongle, t_coder *coder)
{
	t_request	*request;

	request = create_request(coder);
	if (!request)
		return (false);
	pthread_mutex_lock(&dongle->mutex);
	queue_insert(&dongle->queue, request, coder->sim->scheduler);
	while ((queue_get_first(&dongle->queue) != request || !dongle->available)
		&& check_vars(coder, false) == 0)
	{
		if (dongle->cooling_down)
			handle_cooldown(dongle);
		else
			pthread_cond_wait(&dongle->cond, &dongle->mutex);
	}
	if (check_vars(coder, false) != 0)
	{
		remove_request(&dongle->queue, request);
		return (free(request), pthread_mutex_unlock(&dongle->mutex), false);
	}
	queue_pop(&dongle->queue);
	dongle->available = false;
	free(request);
	print_status(coder->sim, coder->id, "has taken a dongle");
	return (pthread_mutex_unlock(&dongle->mutex), true);
}

void	get_dongle_ids(t_coder *coder, int ids[2])
{
	int	temp;

	ids[0] = coder->id - 1;
	ids[1] = coder->id % coder->sim->number_of_coders;
	if (ids[0] > ids[1])
	{
		temp = ids[0];
		ids[0] = ids[1];
		ids[1] = temp;
	}
}

void	release_dongle(t_dongle *dongle, t_coder *coder)
{
	pthread_mutex_lock(&dongle->mutex);
	dongle->available = false;
	dongle->cooling_down = true;
	dongle->cooldown_at = get_current_time() + coder->sim->dongle_cooldown;
	pthread_cond_broadcast(&dongle->cond);
	pthread_mutex_unlock(&dongle->mutex);
}
