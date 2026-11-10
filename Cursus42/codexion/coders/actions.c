/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:32:32 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/10 17:57:26 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	compile(t_simulation *sim, t_coder *coder)
{
	print_status(sim, coder->id, "is compiling");
	coder->last_compile_time = get_current_time();
	usleep(sim->time_to_compile);
}

void	debug(t_simulation *sim, int coder_id)
{
	print_status(sim, coder_id, "is debugging");
	usleep(sim->time_to_compile);
}

void	refactor(t_simulation *sim, int coder_id)
{
	print_status(sim, coder_id, "is refactoring");
	usleep(sim->time_to_compile);
}
