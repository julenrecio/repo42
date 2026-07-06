/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 19:08:27 by azahino-          #+#    #+#             */
/*   Updated: 2026/06/30 10:03:50 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_rotate_both(t_cll *stack_a, t_cll *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

static void	ft_reverse_both(t_cll *stack_a, t_cll *stack_b)
{
	ft_reverse(stack_a);
	ft_reverse(stack_b);
}

static void	ft_swap_both(t_cll *stack_a, t_cll *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}

void	ft_move_reads(t_cll *stack_a, t_cll *stack_b, char *move)
{
	if (ft_strcmp(move, "ra\n") == 0 && ft_strlen(move) == 3)
		ft_rotate(stack_a);
	else if (ft_strcmp(move, "rb\n") == 0 && ft_strlen(move) == 3)
		ft_rotate(stack_b);
	else if (ft_strcmp(move, "rr\n") == 0 && ft_strlen(move) == 3)
		ft_rotate_both(stack_a, stack_b);
	else if (ft_strcmp(move, "pa\n") == 0 && ft_strlen(move) == 3)
		ft_push(stack_b, stack_a);
	else if (ft_strcmp(move, "pb\n") == 0 && ft_strlen(move) == 3)
		ft_push(stack_a, stack_b);
	else if (ft_strcmp(move, "rra\n") == 0 && ft_strlen(move) == 4)
		ft_reverse(stack_a);
	else if (ft_strcmp(move, "rrb\n") == 0 && ft_strlen(move) == 4)
		ft_reverse(stack_b);
	else if (ft_strcmp(move, "rrr\n") == 0 && ft_strlen(move) == 4)
		ft_reverse_both(stack_a, stack_b);
	else if (ft_strcmp(move, "sa\n") == 0 && ft_strlen(move) == 3)
		ft_swap(stack_a);
	else if (ft_strcmp(move, "sb\n") == 0 && ft_strlen(move) == 3)
		ft_swap(stack_b);
	else if (ft_strcmp(move, "ss\n") == 0 && ft_strlen(move) == 3)
		ft_swap_both(stack_a, stack_b);
	else
		ft_show_error();
}

int	ft_is_sorted(t_cll *stack_a)
{
	int		i;
	t_node	*ptr;
	t_node	*ptr_next;

	ptr = stack_a->head;
	ptr_next = stack_a->head->next;
	i = 0;
	while (i < stack_a->size - 1)
	{
		if (ptr->index > ptr_next->index || ptr->value > ptr_next->value)
			return (0);
		i++;
		ptr = ptr_next;
		ptr_next = ptr_next->next;
	}
	return (1);
}
