/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 15:59:34 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/12 13:54:37 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

bool	all_coders_finished(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->number_of_coders)
	{
		if (sim->coders[i].compile_count < sim->number_of_compiles_required)
			return (false);
		i++;
	}
	return (true);
}

void	end_simulation(t_simulation *sim, int coder_id, bool burnout)
{
	int		j;
	bool	ended;

	pthread_mutex_lock(&sim->print_mutex);
	ended = sim->simulation_ended;
	if (!ended)
	{
		if (burnout && all_coders_finished(sim))
			burnout = false;
		sim->simulation_ended = true;
		if (burnout)
			fprintf(stdout, "%lld %d %s\n", get_current_time()
				- sim->start_time, coder_id, "burned out");
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
	int				coder_id;
	bool			burnout;

	sim = (t_simulation *)arg;
	while (true)
	{
		pthread_mutex_lock(&sim->print_mutex);
		if (sim->simulation_ended)
		{
			pthread_mutex_unlock(&sim->print_mutex);
			break ;
		}
		if (all_coders_finished(sim))
		{
			pthread_mutex_unlock(&sim->print_mutex);
			end_simulation(sim, -1, false);
			break ;
		}
		i = 0;
		burnout = false;
		while (i < sim->number_of_coders && !burnout)
		{
			if (sim->coders[i].compile_count < sim->number_of_compiles_required
				&& get_current_time() - sim->coders[i].last_compile_time
				>= sim->time_to_burnout)
			{
				burnout = true;
				coder_id = sim->coders[i].id;
			}
			i++;
		}
		pthread_mutex_unlock(&sim->print_mutex);
		if (burnout)
		{
			end_simulation(sim, coder_id, true);
			break ;
		}
		usleep(10000);
	}
	return (NULL);
}

bool	create_monitor_thread(t_simulation *sim)
{
	if (pthread_create(&sim->monitor, NULL, monitor_routine, sim) != 0)
	{
		printf("Error creating monitor thread");
		return (false);	
	}
	return true;
}

void	wait_monitor_end(t_simulation *sim)
{
	pthread_join(sim->monitor, NULL);
}
