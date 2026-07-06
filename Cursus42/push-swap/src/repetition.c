/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repetition.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:29:55 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/06/24 13:47:01 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_repetition(t_cll *stack_a)
{
	int		i;
	int		j;
	t_node	*ptr;
	t_node	*head;

	i = 0;
	head = stack_a->head;
	while (i < stack_a->size - 1)
	{
		ptr = head->next;
		j = i + 1;
		while (j < stack_a->size)
		{
			if (ptr->value == head->value)
				return (1);
			j++;
			ptr = ptr->next;
		}
		i++;
		head = head->next;
	}
	return (0);
}
