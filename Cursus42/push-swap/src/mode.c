/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 09:57:23 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/07/02 16:55:46 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_mode(t_mode mode, t_cll *stack_a, float disorder)
{
	t_cll	stack_b;

	ft_memset(&stack_b, 0, sizeof(t_cll));
	stack_b.bench = stack_a->bench;
	stack_b.disorder = stack_a->disorder;
	if (stack_a->disorder == 0.0)
		return ;
	if (mode == SIMPLE)
		alg_simple(stack_a, &stack_b);
	else if (mode == MEDIUM)
		alg_medium(stack_a, &stack_b,
			how_many_chunks(stack_a), stack_a->size);
	else if (mode == COMPLEX)
		alg_complex(stack_a, &stack_b);
	else
		alg_adaptive(disorder, stack_a, &stack_b);
	ft_addition(stack_a, &stack_b);
}

void	ft_count_flags(char **argv, t_mode *mode, int *count, t_cll *stack_a)
{
	if (ft_strcmp(argv[*count], "--bench") == 0)
	{
		if (ft_strlen(argv[*count]) == 7)
		{
			(*count)++;
			stack_a->bench = 1;
		}
		else
		{
			if (stack_a->head)
				ft_lstclear(stack_a);
			ft_show_error();
		}
	}
	if (argv[*count])
	{
		if (ft_strcmp(argv[*count], "--simple") == 0)
			*count += ft_check_error(argv[*count], mode, (t_mode)SIMPLE, 8);
		else if (ft_strcmp(argv[*count], "--medium") == 0)
			*count += ft_check_error(argv[*count], mode, (t_mode)MEDIUM, 8);
		else if (ft_strcmp(argv[*count], "--complex") == 0)
			*count += ft_check_error(argv[*count], mode, (t_mode)COMPLEX, 9);
		else if (ft_strcmp(argv[*count], "--adaptive") == 0)
			*count += ft_check_error(argv[*count], mode, (t_mode)ADAPTIVE, 10);
	}
}
