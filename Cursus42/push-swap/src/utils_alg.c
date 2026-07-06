/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_alg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 08:58:10 by azahino-          #+#    #+#             */
/*   Updated: 2026/06/24 19:04:40 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_cost(int index, int size)
{
	if (index <= size / 2)
		return (index);
	else
		return (size - index);
}

int	ft_pos_index(t_cll *stack, int min_index, int max_index)
{
	int		i;
	int		moves;
	t_node	*tmp;
	t_node	*ant;

	i = 0;
	moves = 0;
	tmp = stack->head;
	ant = stack->head;
	while ((tmp->index < min_index || tmp->index > max_index))
	{
		tmp = tmp->next;
		i++;
	}
	while (ant->index < min_index || ant->index > max_index)
	{
		ant = ant->prev;
		moves++;
	}
	if (moves < i)
		i = stack->size - moves;
	return (i);
}

void	ft_addition(t_cll *a, t_cll *b)
{
	long unsigned int	i;

	i = 0;
	while (i < 12)
	{
		a->moves[i] += b->moves[i];
		i++;
	}
}

static float	fractional(float sqrt, float inc_val, int val)
{
	int	i;

	i = 0;
	while (i++ < 3)
	{
		while (sqrt * sqrt <= val)
			sqrt += inc_val;
		sqrt = sqrt - inc_val;
		inc_val = inc_val / 10;
	}
	return (sqrt);
}

float	ft_square_root(int val)
{
	int		right;
	int		left;
	int		mid;
	float	sqrt;

	left = 0;
	right = val;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (mid * mid == val)
		{
			sqrt = mid;
			return (sqrt);
		}
		else if (mid * mid < val)
		{
			sqrt = left;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return (fractional(sqrt, 0.1, val));
}
