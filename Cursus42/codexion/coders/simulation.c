/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:56:42 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/12 13:38:22 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	run(char **argv)
{
	t_simulation	*sim;

	sim = init(argv);
	if (!sim)
		return ;
	if (!create_threads(sim))
		return ;
	if (!create_monitor_thread(sim))
		return ;
	wait_threads_end(sim);
	wait_monitor_end(sim);
	cleanup_simulation(sim);
}
