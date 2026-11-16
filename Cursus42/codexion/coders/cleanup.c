/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:33:52 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/16 12:35:56 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	free_dongle_queues(t_simulation *sim)
{
	int			i;
	t_request	*curr;
	t_request	*next;

	if (!sim->dongles)
		return ;
	i = 0;
	while (i < sim->number_of_coders)
	{
		curr = sim->dongles[i].queue;
		while (curr)
		{
			next = curr->next;
			free(curr);
			curr = next;
		}
		sim->dongles[i].queue = NULL;
		i++;
	}
}

void	cleanup_simulation(t_simulation *sim)
{
	int	i;

	if (!sim)
		return ;
	free_dongle_queues(sim);
	i = 0;
	while (i < sim->initialized_conds)
		pthread_cond_destroy(&sim->dongles[i++].cond);
	i = 0;
	while (i < sim->initialized_mutexes)
		pthread_mutex_destroy(&sim->dongles[i++].mutex);
	free(sim->dongles);
	free(sim->coders);
	if (sim->print_mutex_init)
		pthread_mutex_destroy(&sim->print_mutex);
	if (sim->global_mutex_init)
		pthread_mutex_destroy(&sim->global_mutex);
	free(sim);
}
