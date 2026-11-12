/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:54:16 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/12 13:49:21 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

bool	parse_arguments(char **argv, t_simulation *sim)
{
	return (parse_int(argv[1], &sim->number_of_coders)
		&& parse_int(argv[2], &sim->time_to_burnout)
		&& parse_int(argv[3], &sim->time_to_compile)
		&& parse_int(argv[4], &sim->time_to_debug)
		&& parse_int(argv[5], &sim->time_to_refactor)
		&& parse_int(argv[6], &sim->number_of_compiles_required)
		&& parse_int(argv[7], &sim->dongle_cooldown));
}

t_simulation	*init_simulation(char *argv[])
{
	t_simulation	*sim;

	sim = malloc(sizeof(t_simulation));
	if (!sim)
		return (NULL);
	if (!parse_arguments(argv, sim))
		return (free(sim), NULL);
	if (sim->number_of_coders <= 0 || sim->time_to_burnout <= 0
		|| sim->time_to_compile <= 0 || sim->time_to_debug <= 0
		|| sim->time_to_refactor <= 0 || sim->dongle_cooldown <= 0)
	{
		fprintf(stderr, "Error: Argument parsing error, "
			"argument with negative or zero value\n");
		return (free(sim), NULL);
	}
	sim->start_time = get_current_time();
	sim->scheduler = argv[8];
	sim->coders = malloc(sizeof(t_coder) * sim->number_of_coders);
	if (!sim->coders)
		return (free(sim), NULL);
	sim->dongles = malloc(sizeof(t_dongle) * sim->number_of_coders);
	if (!sim->dongles)
		return (free(sim->coders), free(sim), NULL);
	sim->simulation_ended = false;
	return (sim);
}

void	init_coders(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->number_of_coders)
	{
		sim->coders[i].id = i;
		sim->coders[i].compile_count = 0;
		sim->coders[i].last_compile_time = sim->start_time;
		sim->coders[i].sim = sim;
		i++;
	}
}

bool	init_dongles(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->number_of_coders)
	{
		if (pthread_mutex_init(&sim->dongles[i].mutex, NULL) != 0)
		{
			fprintf(stderr, "Error on mutex init");
			return (false);
		}
		sim->initialized_mutexes++;
		if (pthread_cond_init(&sim->dongles[i].cond, NULL) != 0)
		{
			fprintf(stderr, "Error on cond init");
			return (false);
		}
		sim->initialized_conds++;
		sim->dongles[i].available = true;
		sim->dongles[i].cooling_down = false;
		sim->dongles[i].cooldown_at = 0;
		sim->dongles[i].queue = NULL;
		i++;
	}
	return (true);
}

t_simulation	*init(char **argv)
{
	t_simulation	*sim;

	sim = init_simulation(argv);
	if (!sim)
		return (NULL);
	init_coders(sim);
	sim->initialized_conds = 0;
	sim->initialized_mutexes = 0;
	if (pthread_mutex_init(&sim->print_mutex, NULL) != 0)
		return (NULL);
	if (!init_dongles(sim))
	{
		cleanup_simulation(sim);
		return (NULL);
	}
	return (sim);
}
