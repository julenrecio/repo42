/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:37:38 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/03 18:12:19 by jrecio-t         ###   ########.fr       */
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

long get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * (long)1000 + tv.tv_usec / 1000);
}

bool ft_atol(const char *str, long *result)
{
    char    *endptr;
    long    value;

    errno = 0;
    value = strtol(str, &endptr, 10);
    if (errno == ERANGE || str == endptr || *endptr != '\0')
        return (false);
    *result = value;
    return (true);
}

bool parse_int(const char *str, long *result)
{
    long value;

    if (!ft_atol(str, &value))
        return (false);
    if (value < INT_MIN || value > INT_MAX)
        return (false);
    *result = (int)value;
    return (true);
}

t_simulation	*init_simulation(char *argv[])
{
	t_simulation	*sim;

	sim = malloc(sizeof(t_simulation));
	if (!sim)
		return (NULL);
	if (!parse_int(argv[1], &sim->number_of_coders)
		|| !parse_int(argv[2], &sim->time_to_burnout)
		|| !parse_int(argv[3], &sim->time_to_compile)
		|| !parse_int(argv[4], &sim->time_to_debug)
		|| !parse_int(argv[5], &sim->time_to_refactor)
		|| !parse_int(argv[6], &sim->number_of_compiles_required)
		|| !parse_int(argv[7], &sim->dongle_cooldown))
    {
        free(sim);
        return (NULL);
    }
	sim->start_time = get_current_time();
	sim->scheduler = argv[8];
	sim->coders = malloc(sizeof(t_coder) * sim->number_of_coders);
	if (!sim->coders)
		return (free(sim), NULL);
	sim->dongles = malloc(sizeof(t_dongle) * sim->number_of_coders);
	if (!sim->dongles)
		return (free(sim->coders), free(sim), NULL);
	return (sim);
}

void	init_coders(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->number_of_coders)
	{
		if (pthread_create(&sim->coders[i].thread, NULL,
				coder_routine, &sim->coders[i]) != 0)
			printf("Error creating a thread");
		sim->coders[i].id = i;
		sim->coders[i].compile_count = 0;
		sim->coders[i].last_compile_time = sim->start_time;
		sim->coders[i].state = WAITING;
		pthread_join(sim->coders[i].thread, NULL);
		i++;
	}
	printf("All coders initialized correctly\n");
	return ;
}

void	init_donlges(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->number_of_coders)
	{
		pthread_mutex_init(&sim->dongles[i].mutex, NULL);
		pthread_cond_init(&sim->dongles[i].cond, NULL);
		sim->dongles[i].available = 0;
		i++;
	}
	printf("All dongles initialized correctly");
	return ;
}

int	main(int argc, char **argv)
{
	t_simulation	*sim;

	if (argc == 9)
	{
		if (strcmp(argv[argc - 1], "fifo") == 0
			|| strcmp(argv[argc - 1], "edf") == 0)
		{
			sim = init_simulation(argv);
			if (!sim)
			{
				fprintf(stderr, "Error: invalid arguments\n");
				return (1);
			}
			init_coders(sim);
			init_donlges(sim);
			printf("\nNumber of coders: %ld", sim->number_of_coders);
		}
		else
			fprintf(stderr, "Error: schedule (last arg) must be"
				"'fifo' or 'edf'\n");
	}
	else
	{
		fprintf(stderr, "Error, too few arguments, args must be in the"
			"following format:"
			"\n./codexion number_of_coders time_to_burnout time_to_compile "
			"time_to_debug time_to_refactor number_of_compiles_required "
			"dongle_cooldown scheduler\n");
	}
}

// ./codexion 8 3000 800 300 500 5 200 fifo