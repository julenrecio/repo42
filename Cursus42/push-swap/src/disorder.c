/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 10:41:11 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/06/25 15:43:34 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

double	ft_compute_disorder(t_cll *stack_a)
{
	double	mistakes;
	double	total_pairs;
	int		i;
	int		j;
	t_node	*ptr;

	i = 0;
	total_pairs = 0;
	mistakes = 0;
	while (i < stack_a->size - 1)
	{
		ptr = stack_a->head->next;
		j = i + 1;
		while (j++ < stack_a->size)
		{
			total_pairs++;
			if (ptr->value < stack_a->head->value)
				mistakes++;
			ptr = ptr->next;
		}
		i++;
		stack_a->head = stack_a->head->next;
	}
	stack_a->head = stack_a->head->next;
	return (mistakes / total_pairs);
}
