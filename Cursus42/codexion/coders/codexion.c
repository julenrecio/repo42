/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:37:38 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/04 17:11:17 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int argc, char **argv)
{
	if (argc == 9)
	{
		if (strcmp(argv[argc - 1], "fifo") == 0
			|| strcmp(argv[argc - 1], "edf") == 0)
			run(argv);
		else
			fprintf(stderr, "Error: schedule (last arg) must be "
				"'fifo' or 'edf'\n");
	}
	else
	{
		fprintf(stderr, "Error, too few arguments, args must be in the "
			"following format:"
			"\n./codexion number_of_coders time_to_burnout time_to_compile "
			"time_to_debug time_to_refactor number_of_compiles_required "
			"dongle_cooldown scheduler\n");
	}
}
