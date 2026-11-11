/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 15:59:34 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/11 17:53:09 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	end_simulation(t_simulation *sim, int coder_id)
{
	int		j;
	bool	ended;

	pthread_mutex_lock(&sim->print_mutex);
	ended = sim->simulation_ended;
	if (!ended)
	{
		sim->simulation_ended = true;
		fprintf(stdout, "%lld %d %s\n", get_current_time() - sim->start_time,
			coder_id, "burned out");
	}
	pthread_mutex_unlock(&sim->print_mutex);
	if (ended)
		return ;
	j = 0;
	while (j < sim->number_of_coders)
	{
		pthread_mutex_lock(&sim->dongles[j].mutex);
		pthread_cond_broadcast(&sim->dongles[j].cond);
		pthread_mutex_unlock(&sim->dongles[j].mutex);
		j++;
	}
}

void	*monitor_routine(void *arg)
{
	t_simulation	*sim;
	int				i;
	bool			burnout;

	sim = (t_simulation *)arg;
	pthread_mutex_lock(&sim->print_mutex);
	while (!sim->simulation_ended)
	{
		pthread_mutex_unlock(&sim->print_mutex);
		i = 0;
		while (i < sim->number_of_coders && !burnout)
		{
			burnout = false;
			pthread_mutex_lock(&sim->print_mutex);
			if (get_current_time() - sim->coders[i].last_compile_time
				>= sim->time_to_burnout)
				burnout = true;
			pthread_mutex_unlock(&sim->print_mutex);
			if (burnout)
				end_simulation(sim, sim->coders[i].id);
			i++;
		}
		usleep(10000);
		pthread_mutex_lock(&sim->print_mutex);
	}
	return (NULL);
}

void	create_monitor_thread(t_simulation *sim)
{
	pthread_create(&sim->monitor, NULL, monitor_routine, sim);
}

void	wait_monitor_end(t_simulation *sim)
{
	pthread_join(sim->monitor, NULL);
}
