/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 15:59:34 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/16 12:23:48 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static bool	all_coders_finished(t_simulation *sim)
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

static void	wake_all_dongles(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->number_of_coders)
	{
		pthread_mutex_lock(&sim->dongles[i].mutex);
		pthread_cond_broadcast(&sim->dongles[i].cond);
		pthread_mutex_unlock(&sim->dongles[i].mutex);
		i++;
	}
}

void	end_simulation(t_simulation *sim, int coder_id, bool burnout)
{
	bool	ended;

	pthread_mutex_lock(&sim->global_mutex);
	ended = sim->simulation_ended;
	if (!ended)
	{
		if (burnout && all_coders_finished(sim))
			burnout = false;
		sim->simulation_ended = true;
		if (burnout)
		{
			pthread_mutex_lock(&sim->print_mutex);
			fprintf(stdout, "%lld %d %s\n", get_current_time()
				- sim->start_time, coder_id, "burned out");
			pthread_mutex_unlock(&sim->print_mutex);
		}
	}
	pthread_mutex_unlock(&sim->global_mutex);
	if (!ended)
		wake_all_dongles(sim);
}

static bool	check_monitor_conditions(t_simulation *sim)
{
	int	i;

	pthread_mutex_lock(&sim->global_mutex);
	if (sim->simulation_ended)
		return (pthread_mutex_unlock(&sim->global_mutex), true);
	if (all_coders_finished(sim))
	{
		pthread_mutex_unlock(&sim->global_mutex);
		end_simulation(sim, -1, false);
		return (true);
	}
	i = 0;
	while (i < sim->number_of_coders)
	{
		if (sim->coders[i].compile_count < sim->number_of_compiles_required
			&& get_current_time() - sim->coders[i].last_compile_time
			>= sim->time_to_burnout)
		{
			pthread_mutex_unlock(&sim->global_mutex);
			return (end_simulation(sim, sim->coders[i].id, true), true);
		}
		i++;
	}
	pthread_mutex_unlock(&sim->global_mutex);
	return (false);
}

void	*monitor_routine(void *arg)
{
	t_simulation	*sim;

	sim = (t_simulation *)arg;
	while (true)
	{
		if (check_monitor_conditions(sim))
			break ;
		usleep(1000);
	}
	return (NULL);
}
