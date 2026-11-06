/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:56:42 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/06 13:41:36 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	run(char **argv)
{
	t_simulation	*sim;

	sim = init(argv);
	if (!sim)
		return ;
	create_threads(sim);
	wait_threads_end(sim);
	cleanup_simulation(sim);
}
