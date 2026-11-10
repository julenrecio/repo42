/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:37:19 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/10 17:57:06 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	print_status(t_simulation *sim, int coder_id, char *message)
{
	long long	time;

	pthread_mutex_lock(&sim->print_mutex);
	if (!sim->simulation_ended)
	{
		time = get_current_time() - sim->start_time;
		fprintf(stdout, "%lld %d %s\n", time, coder_id, message);
	}
	pthread_mutex_unlock(&sim->print_mutex);
}

void	*coder_routine(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	printf("Coder ID: %d\n", coder->id);
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
	printf("All threads created correctly\n");
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
	printf("All coders finished correctly\n");
	return ;
}
