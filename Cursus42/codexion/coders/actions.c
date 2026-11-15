/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:32:32 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/14 21:55:05 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	compile(t_coder *coder)
{
	long long	now;

	now = get_current_time();
	pthread_mutex_lock(&coder->sim->global_mutex);
	coder->last_compile_time = now;
	if (!coder->sim->simulation_ended)
		fprintf(stdout, "%lld %d is compiling\n",
			now - coder->sim->start_time, coder->id);
	pthread_mutex_unlock(&coder->sim->global_mutex);
	usleep(coder->sim->time_to_compile * 1000);
}

void	debug(t_coder *coder)
{
	print_status(coder->sim, coder->id, "is debugging");
	usleep(coder->sim->time_to_debug * 1000);
}

void	refactor(t_coder *coder)
{
	print_status(coder->sim, coder->id, "is refactoring");
	usleep(coder->sim->time_to_refactor * 1000);
}
