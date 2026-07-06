/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 19:00:08 by azahino-          #+#    #+#             */
/*   Updated: 2026/07/01 10:25:18 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_cll	stack_a;
	t_cll	stack_b;

	ft_memset(&stack_a, 0, sizeof(t_cll));
	ft_memset(&stack_b, 0, sizeof(t_cll));
	ft_assignment(argc - 1, argv + 1, &stack_a);
	if (ft_repetition(&stack_a))
	{
		if (stack_a.head)
			ft_lstclear(&stack_a);
		ft_show_error();
	}
	ft_gnl_loop(&stack_a, &stack_b);
	if (stack_b.size == 0 && ft_is_sorted(&stack_a))
		ft_printf(1, "OK\n");
	else
		ft_printf(1, "KO\n");
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
