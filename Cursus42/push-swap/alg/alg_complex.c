/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_complex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:04:18 by azahino-          #+#    #+#             */
/*   Updated: 2026/06/24 17:06:35 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	max_bits(int max_num)
{
	int	bits;

	bits = 0;
	while (max_num > 0)
	{
		max_num = max_num / 2;
		bits++;
	}
	return (bits);
}

void	alg_complex(t_cll *stack_a, t_cll *stack_b)
{
	int	bits;
	int	current_bit;
	int	size;

	current_bit = 0;
	bits = max_bits(stack_a->size - 1);
	while (current_bit < bits)
	{
		size = stack_a->size;
		while (size-- > 0)
		{
			if (((stack_a->head->index >> current_bit) & 1) == 0)
				ft_pb(stack_a, stack_b);
			else
				ft_ra(stack_a);
		}
		while (stack_b->head)
			ft_pa(stack_a, stack_b);
		current_bit++;
	}
	ft_addition(stack_a, stack_b);
}
