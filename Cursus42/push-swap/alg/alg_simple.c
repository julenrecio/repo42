/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:04:12 by azahino-          #+#    #+#             */
/*   Updated: 2026/07/01 13:49:38 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	alg_simple(t_cll *stack_a, t_cll *stack_b)
{
	int		size;
	int		cost;
	int		pos;
	int		index;

	size = stack_a->size;
	cost = 0;
	index = 0;
	while (size > 0)
	{
		pos = ft_pos_index(stack_a, index, index);
		cost = ft_cost(pos, size);
		if (pos <= size / 2)
			while (cost-- > 0)
				ft_ra(stack_a);
		else if (pos > size / 2)
			while (cost-- > 0)
				ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
		size--;
		index++;
	}
	size = stack_b->size;
	while (cost++ < size - 1)
		ft_pa(stack_a, stack_b);
}

void	alg_simple_medium(t_cll *stack_a, t_cll *stack_b)
{
	int		size;
	int		cost;
	int		pos;

	size = stack_b->size;
	cost = 0;
	while (size > 0)
	{
		pos = ft_pos_index(stack_b, size - 1, size - 1);
		cost = ft_cost(pos, size);
		if (pos <= size / 2)
			while (cost-- > 0)
				ft_rb(stack_b);
		else if (pos > size / 2)
			while (cost-- > 0)
				ft_rrb(stack_b);
		ft_pa(stack_a, stack_b);
		size--;
	}
}
