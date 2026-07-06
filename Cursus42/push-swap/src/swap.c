/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 10:16:25 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/06/28 21:31:29 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_cll *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;
	t_node	*last;

	first = stack->head;
	if (first == NULL || first->next == first)
		return ;
	if (first->next->next == first)
	{
		stack->head = first->next;
		return ;
	}
	last = first->prev;
	second = first->next;
	third = second->next;
	second->prev = last;
	second->next = first;
	first->prev = second;
	first->next = third;
	third->prev = first;
	last->next = second;
	stack->head = second;
}

void	ft_ss(t_cll *a, t_cll *b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf(1, "ss\n");
	a->moves[8]++;
	a->moves[11]++;
}

void	ft_sa(t_cll *a)
{
	ft_swap(a);
	ft_printf(1, "sa\n");
	a->moves[6]++;
	a->moves[11]++;
}

void	ft_sb(t_cll *b)
{
	ft_swap(b);
	ft_printf(1, "sb\n");
	b->moves[7]++;
	b->moves[11]++;
}
