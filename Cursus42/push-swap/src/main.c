/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:45:49 by azahino-          #+#    #+#             */
/*   Updated: 2026/07/02 18:16:46 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	int			count;
	t_cll		stack_a;
	t_mode		mode;

	count = 1;
	mode = ADAPTIVE;
	if (argc == 1)
		ft_show_error();
	ft_memset(&stack_a, 0, sizeof(t_cll));
	ft_count_flags(argv, &mode, &count, &stack_a);
	ft_assignment(argc - count, argv + count, &stack_a);
	if (ft_repetition(&stack_a))
	{
		if (stack_a.head)
			ft_lstclear(&stack_a);
		ft_show_error();
	}
	if (stack_a.size > 1)
		stack_a.disorder = ft_compute_disorder(&stack_a);
	ft_mode(mode, &stack_a, stack_a.disorder);
	if (stack_a.bench == 1)
		ft_bench(stack_a.disorder, mode, &stack_a);
	ft_lstclear(&stack_a);
	return (0);
}
