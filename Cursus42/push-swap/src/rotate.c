/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 10:22:24 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/06/30 09:57:05 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate(t_cll *stack)
{
	if (!(stack->head == NULL))
		stack->head = stack->head->next;
}

void	ft_ra(t_cll *a)
{
	ft_rotate(a);
	ft_printf(1, "ra\n");
	a->moves[0]++;
	a->moves[11]++;
}

void	ft_rb(t_cll *b)
{
	ft_rotate(b);
	ft_printf(1, "rb\n");
	b->moves[1]++;
	b->moves[11]++;
}

void	ft_rr(t_cll *a, t_cll *b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf(1, "rr\n");
	a->moves[2]++;
	a->moves[11]++;
}
