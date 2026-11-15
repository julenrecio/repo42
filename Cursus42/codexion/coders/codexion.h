/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:37:30 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/16 00:17:16 by jrecio-t         ###   ########.fr       */
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

typedef struct s_request
{
	int					coder_id;
	long long			request_time;
	long long			deadline;
	struct s_request	*next;
}	t_request;

typedef struct s_dongle
{
	pthread_cond_t	cond;
	pthread_mutex_t	mutex;
	bool			available;
	bool			cooling_down;
	long long		cooldown_at;
	t_request		*queue;
}	t_dongle;

typedef struct s_simulation	t_simulation;

typedef struct s_coder
{
	int				id;
	int				compile_count;
	long long		last_compile_time;
	pthread_t		thread;
	t_simulation	*sim;
}	t_coder;

typedef struct s_simulation
{
	long long		start_time;
	int				number_of_coders;
	int				time_to_burnout;
	int				time_to_compile;
	int				time_to_debug;
	int				time_to_refactor;
	int				number_of_compiles_required;
	int				dongle_cooldown;
	char			*scheduler;
	int				initialized_conds;
	int				initialized_mutexes;
	int				created_threads;
	bool			simulation_ended;
	t_coder			*coders;
	t_dongle		*dongles;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	global_mutex;
	pthread_t		monitor;
}	t_simulation;

t_simulation	*init(char **argv);
bool			parse_int(const char *str, int *result);
long long		get_current_time(void);
void			cleanup_simulation(t_simulation *sim);
bool			create_threads(t_simulation *sim);
void			wait_threads_end(t_simulation *sim);
void			get_dongle_ids(t_coder *coder, int ids[2]);
bool			adquire_dongle(t_dongle *dongle, t_coder *coder);
void			release_dongle(t_dongle *dongle, t_coder *coder);
t_request		*queue_get_first(t_request **queue);
t_request		*create_request(t_coder *coder);
t_request		*queue_pop(t_request **queue);
void			print_status(t_simulation *sim, int coder_id, char *message);
void			compile(t_coder *coder);
void			debug(t_coder *coder);
void			refactor(t_coder *coder);
void			*monitor_routine(void *arg);
void			end_simulation(t_simulation *sim, int coder_id, bool burnout);
int				check_vars(t_coder *coder, bool check_count);
void			queue_insert(t_request **queue, t_request *request,
					char *scheduler);

#endif