/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:37:19 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/13 13:36:08 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	print_status(t_simulation *sim, int coder_id, char *message)
{
	long long	time;

	pthread_mutex_lock(&sim->global_mutex);
	if (!sim->simulation_ended)
	{
		pthread_mutex_lock(&sim->print_mutex);
		time = get_current_time() - sim->start_time;
		fprintf(stdout, "%lld %d %s\n", time, coder_id, message);
		pthread_mutex_unlock(&sim->print_mutex);
	}
	pthread_mutex_unlock(&sim->global_mutex);
}

void	*coder_routine(void *arg)
{
	t_coder	*coder;
	int		ids[2];

	coder = (t_coder *)arg;
	get_dongle_ids(coder, ids);
	while (coder->compile_count < coder->sim->number_of_compiles_required)
	{
		adquire_dongle(&coder->sim->dongles[ids[0]], coder);
		adquire_dongle(&coder->sim->dongles[ids[1]], coder);
		compile(coder);
		pthread_mutex_lock(&coder->sim->global_mutex);
		coder->compile_count++;
		pthread_mutex_unlock(&coder->sim->global_mutex);
		release_dongle(&coder->sim->dongles[ids[0]], coder);
		release_dongle(&coder->sim->dongles[ids[1]], coder);
		if (coder->compile_count
			< coder->sim->number_of_compiles_required)
		{
			debug(coder);
			refactor(coder);
		}
	}
	return (NULL);
}

bool	create_threads(t_simulation *sim)
{
	int	i;

	i = 0;
	sim->created_threads = 0;
	while (i < sim->number_of_coders)
	{
		if (pthread_create(&sim->coders[i].thread, NULL,
				coder_routine, &sim->coders[i]) != 0)
		{
			printf("Error creating a thread");
			return (false);
		}
		sim->created_threads++;
		i++;
	}
	return (true);
}

void	wait_threads_end(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->created_threads)
	{
		pthread_join(sim->coders[i].thread, NULL);
		i++;
	}
	return ;
}
