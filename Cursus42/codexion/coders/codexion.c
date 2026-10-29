/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:37:38 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/10/29 15:47:11 by jrecio-t         ###   ########.fr       */
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

t_coder	*create_threads(int num_coders)
{
	t_coder		*coders;
	int			i;

	coders = malloc(sizeof(t_coder) * num_coders);
	i = 0;
	while (i < num_coders)
	{
		if (pthread_create(&coders[i].thread, NULL,
				coder_routine, &coders[i]) != 0)
			printf("Error creating a thread");
		coders[i].id = i;
		pthread_join(coders[i].thread, NULL);
		i++;
	}
	printf("All threads created correctly");
	return (coders);
}

t_simulation	load_args(char **argv)
{
	t_simulation	args;

	args.number_of_coders = atoi(argv[1]);
	args.time_to_burnout = atoi(argv[2]);
	args.time_to_compile = atoi(argv[3]);
	args.time_to_debug = atoi(argv[4]);
	args.time_to_refactor = atoi(argv[5]);
	args.number_of_compiles_required = atoi(argv[6]);
	args.dongle_cooldown = atoi(argv[7]);
	args.scheduler = argv[8];
	args.coders = create_threads(args.number_of_coders);
	return (args);
}

int	main(int argc, char **argv)
{
	t_simulation	args;

	if (argc == 9)
	{
		if (strcmp(argv[argc - 1], "fifo") == 0
			|| strcmp(argv[argc - 1], "edf") == 0)
		{
			args = load_args(argv);
			printf("\nNumber of coders: %ld", args.number_of_coders);
		}
		else
			printf("Error: schedule (last arg) must be 'fifo' or 'edf'\n");
	}
	else
	{
		printf("Error, to few arguments, args must be in the following format:"
			"\n./codexion number_of_coders time_to_burnout time_to_compile "
			"time_to_debug time_to_refactor number_of_compiles_required "
			"dongle_cooldown scheduler\n");
	}
}

// ./codexion 8 3000 800 300 500 5 200 fifo