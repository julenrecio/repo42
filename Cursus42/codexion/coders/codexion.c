/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:37:38 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/15 23:30:40 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static bool	run(char **argv)
{
	t_simulation	*sim;
	bool			monitor_created;

	sim = init(argv);
	if (!sim)
		return (false);
	monitor_created = false;
	if (!create_threads(sim))
		end_simulation(sim, -1, false);
	else if (pthread_create(&sim->monitor, NULL, monitor_routine, sim) != 0)
	{
		fprintf(stderr, "Error creating monitor thread");
		end_simulation(sim, -1, false);
	}
	else
		monitor_created = true;
	wait_threads_end(sim);
	if (monitor_created)
		pthread_join(sim->monitor, NULL);
	cleanup_simulation(sim);
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc == 9)
	{
		if (strcmp(argv[argc - 1], "fifo") == 0
			|| strcmp(argv[argc - 1], "edf") == 0)
		{
			if (!run(argv))
				return (1);
		}
		else
		{
			fprintf(stderr, "Error: schedule (last arg) must be "
				"'fifo' or 'edf'\n");
			return (1);
		}
	}
	else
	{
		fprintf(stderr, "Error, bad arguments, args must be in the "
			"following format:"
			"\n./codexion number_of_coders time_to_burnout time_to_compile "
			"time_to_debug time_to_refactor number_of_compiles_required "
			"dongle_cooldown scheduler\n");
		return (1);
	}
	return (0);
}
