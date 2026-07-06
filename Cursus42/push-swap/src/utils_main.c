/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahino- <azahino-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:18:59 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/06/30 14:42:24 by azahino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_index_sorted(int stack_size, t_cll *stack_a)
{
	int		node_rest;
	int		moves;
	int		index;
	t_node	*ptr;
	t_node	*move;

	if (!stack_a->head)
		ft_show_error();
	ptr = stack_a->head;
	move = stack_a->head->next;
	node_rest = 0;
	while (node_rest++ < stack_size)
	{
		moves = 0;
		index = 0;
		while (moves++ < stack_size)
		{
			if (ptr->value > move->value)
				index++;
			move = move->next;
		}
		ptr->index = index;
		ptr = ptr->next;
	}
}

static char	*ft_loop(int *argc, char **argv)
{
	char	*tmp;
	char	*args;

	args = ft_strdup("");
	while (*argc > 0)
	{
		tmp = args;
		args = ft_strjoin(args, *argv);
		free(tmp);
		argv++;
		(*argc)--;
	}
	return (args);
}

void	ft_assignment(int argc, char **argv, t_cll *stack_a)
{
	long int	value;
	t_node		*ptr;
	char		*args;
	char		**tmp;
	int			count;

	args = ft_loop(&argc, argv);
	count = ft_count_words(args);
	tmp = ft_split(args);
	free(args);
	while (tmp[argc])
	{
		value = ft_atoi(tmp[argc++]);
		if (value > 2147483647 || value < -2147483648)
		{
			if (stack_a->head)
				ft_lstclear(stack_a);
			ft_freeall(tmp, count);
			ft_show_error();
		}
		ptr = ft_lstnew(value);
		ft_lstadd_back(stack_a, ptr);
	}
	ft_freeall(tmp, count);
	ft_index_sorted(stack_a->size, stack_a);
}

void	ft_freeall(char **array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
