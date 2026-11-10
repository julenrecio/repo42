/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:19:44 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/10 17:57:20 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

struct timespec	ms_to_timespec(long long milliseconds)
{
	struct timespec	deadline;

	deadline.tv_sec = milliseconds / 1000;
	deadline.tv_nsec = (milliseconds % 1000) * 1000000;
	return (deadline);
}

void	handle_cooldown(t_dongle *dongle)
{
	struct timespec	deadline;

	if (get_current_time() < dongle->cooldown_at)
	{
		deadline = ms_to_timespec(dongle->cooldown_at);
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

void	adquire_dongle(t_dongle *dongle, t_coder *coder, t_simulation *sim)
{
	t_request		*request;

	request = create_request(coder, sim);
	if (!request)
		return ;
	pthread_mutex_lock(&dongle->mutex);
	queue_insert(&dongle->queue, request, sim->scheduler);
	while (queue_get_first(&dongle->queue) != request || !dongle->available)
	{
		if (dongle->cooling_down)
			handle_cooldown(dongle);
		else
			pthread_cond_wait(&dongle->cond, &dongle->mutex);
	}
	queue_pop(&dongle->queue);
	dongle->available = false;
	free(request);
	print_status(sim, coder->id, "has taken a dongle");
	pthread_mutex_unlock(&dongle->mutex);
}

void	get_donlges(t_simulation *sim, t_coder *coder)
{
	int	left_dongle_index;
	int	right_dongle_index;
	int	temp;

	left_dongle_index = coder->id;
	right_dongle_index = (coder->id + 1) % sim->number_of_coders;
	if (left_dongle_index > right_dongle_index)
	{
		temp = left_dongle_index;
		left_dongle_index = right_dongle_index;
		right_dongle_index = temp;
	}
	adquire_dongle(&sim->dongles[left_dongle_index], coder, sim);
	adquire_dongle(&sim->dongles[right_dongle_index], coder, sim);
}

void	release_dongle(t_dongle *dongle, t_coder *coder, t_simulation *sim)
{
	pthread_mutex_lock(&dongle->mutex);
	dongle->available = false;
	dongle->cooling_down = true;
	dongle->cooldown_at = get_current_time() + sim->dongle_cooldown;
	print_status(sim, coder->id, "has released a dongle");
	pthread_cond_broadcast(&dongle->cond);
	pthread_mutex_unlock(&dongle->mutex);
}
