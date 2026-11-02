/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:37:38 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/02 13:22:16 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*coder_routine(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	printf("Coder ID: %d\n", coder->id);
	return (NULL);
}

t_simulation *init_simulation(char *argv[])
{
	t_simulation	*sim;
	sim = malloc(sizeof(t_simulation));
	sim->number_of_coders = atoi(argv[1]);
	sim->time_to_burnout = atoi(argv[2]);
	sim->time_to_compile = atoi(argv[3]);
	sim->time_to_debug = atoi(argv[4]);
	sim->time_to_refactor = atoi(argv[5]);
	sim->number_of_compiles_required = atoi(argv[6]);
	sim->dongle_cooldown = atoi(argv[7]);
	sim->scheduler = argv[8];
	sim->coders = malloc(sizeof(t_coder) * sim->number_of_coders);
	sim->dongles = malloc(sizeof(t_dongle) * sim->number_of_coders);
	return (sim);
}

void	create_threads(t_simulation *sim)
{
	int			i;

	i = 0;
	while (i < sim->number_of_coders)
	{
		if (pthread_create(&sim->coders[i].thread, NULL,
				coder_routine, &sim->coders[i]) != 0)
			printf("Error creating a thread");
		sim->coders[i].id = i;
		pthread_join(sim->coders[i].thread, NULL);
		i++;
	}
	printf("All threads created correctly");
	return ;
}

int	main(int argc, char **argv)
{
	t_simulation *sim;

	if (argc == 9)
	{
		if (strcmp(argv[argc - 1], "fifo") == 0
			|| strcmp(argv[argc - 1], "edf") == 0)
		{
			sim = init_simulation(argv);
			create_threads(sim);
			printf("\nNumber of coders: %ld", sim->number_of_coders);
		}
		else
			fprintf(stderr, "Error: schedule (last arg) must be 'fifo' or 'edf'\n");
	}
	else
	{
		fprintf(stderr, "Error, too few arguments, args must be in the following format:"
			"\n./codexion number_of_coders time_to_burnout time_to_compile "
			"time_to_debug time_to_refactor number_of_compiles_required "
			"dongle_cooldown scheduler\n");
	}
}

// ./codexion 8 3000 800 300 500 5 200 fifo