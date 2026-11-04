/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:37:30 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/04 17:28:52 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>
# include <errno.h>
# include <limits.h>

typedef enum state
{
	WAITING,
	COMPILING,
	DEBUGGING,
	REFACTORING,
	BURNED_OUT,
	FINISHED
}	t_state;

typedef struct s_dongle
{
	pthread_cond_t	cond;
	pthread_mutex_t	mutex;
	bool			available;
}	t_dongle;

typedef struct s_coder
{
	int			id;
	int			compile_count;
	t_state		state;
	long long	last_compile_time;
	pthread_t	thread;
}	t_coder;

typedef struct s_simulation
{
	long long	start_time;
	int			number_of_coders;
	int			time_to_burnout;
	int			time_to_compile;
	int			time_to_debug;
	int			time_to_refactor;
	int			number_of_compiles_required;
	int			dongle_cooldown;
	char		*scheduler;
	t_coder		*coders;
	t_dongle	*dongles;
}	t_simulation;

void			run(char **argv);
t_simulation	*init(char **argv);
bool			parse_int(const char *str, int *result);
long long		get_current_time(void);

#endif