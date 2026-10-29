/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:37:30 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/10/29 15:46:11 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef enum state
{
	COMPILING,
	DEBUGGING,
	REFACTORING,
	WAITING,
	BURNED_OUT,
	FINISHED
}	t_state;

typedef struct s_coder
{
	int			id;
	int			compile_count;
	t_state		state;
	long		last_compile_time;
	pthread_t	thread;
}	t_coder;

typedef struct s_simulation
{
	long		number_of_coders;
	long		time_to_burnout;
	long		time_to_compile;
	long		time_to_debug;
	long		time_to_refactor;
	long		number_of_compiles_required;
	long		dongle_cooldown;
	char		*scheduler;
	t_coder		*coders;

}	t_simulation;

#endif