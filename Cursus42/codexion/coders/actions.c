/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:32:32 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/16 15:54:36 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	smart_sleep(long long duration_ms, t_simulation *sim)
{
	long long	start;
	bool		ended;

	start = get_current_time();
	while (get_current_time() - start < duration_ms)
	{
		pthread_mutex_lock(&sim->global_mutex);
		ended = sim->simulation_ended;
		pthread_mutex_unlock(&sim->global_mutex);
		if (ended)
			break ;
		usleep(1000);
	}
}

void	compile(t_coder *coder)
{
	long long	now;

	pthread_mutex_lock(&coder->sim->global_mutex);
	now = get_current_time();
	coder->last_compile_time = now;
	if (!coder->sim->simulation_ended)
		fprintf(stdout, "%lld %d is compiling\n",
			now - coder->sim->start_time, coder->id);
	pthread_mutex_unlock(&coder->sim->global_mutex);
	smart_sleep(coder->sim->time_to_compile, coder->sim);
}

void	debug(t_coder *coder)
{
	print_status(coder->sim, coder->id, "is debugging");
	smart_sleep(coder->sim->time_to_debug, coder->sim);
}

void	refactor(t_coder *coder)
{
	print_status(coder->sim, coder->id, "is refactoring");
	smart_sleep(coder->sim->time_to_refactor, coder->sim);
}
