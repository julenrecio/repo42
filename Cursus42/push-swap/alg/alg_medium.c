/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_medium.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:04:16 by azahino-          #+#    #+#             */
/*   Updated: 2026/07/01 13:58:49 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	moves(t_cll *stack_a, t_cll *stack_b, int start, int end)
{
	ft_pb(stack_a, stack_b);
	if (stack_b->head && stack_b->head->index <= (start + end) / 2)
		ft_rb(stack_b);
}

static int	def_end(int i, int n_chunks, int size, int c_size)
{
	if (i == n_chunks - 1)
		return (size - 1);
	else
		return ((i + 1) * c_size - 1);
}

static void	move_to_chunk(t_cll *a, t_cll *b, int start, int end)
{
	int	pos_a;
	int	mid;

	mid = (start + end) / 2;
	pos_a = ft_pos_index(a, start, end);
	if (b->head && b->head->index <= mid
		&& pos_a <= a->size / 2)
		ft_rr(a, b);
	else if (pos_a <= a->size / 2)
		ft_ra(a);
	else
		ft_rra(a);
}

void	alg_medium(t_cll *stk_a, t_cll *stack_b, int n_chunks, int size)
{
	int	i;
	int	start;
	int	end;
	int	c_size;
	int	count;

	c_size = stk_a->size / n_chunks;
	i = -1;
	while (++i < n_chunks)
	{
		start = i * c_size;
		count = start;
		end = def_end(i, n_chunks, size, c_size);
		while (count <= end)
		{
			if (stk_a->head->index >= (i * c_size) && stk_a->head->index <= end)
			{
				moves(stk_a, stack_b, start, end);
				count++;
			}
			else
				move_to_chunk(stk_a, stack_b, start, end);
		}
	}
	alg_simple_medium(stk_a, stack_b);
}
