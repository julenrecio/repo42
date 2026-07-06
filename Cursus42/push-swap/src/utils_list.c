/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:22:31 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/06/30 10:50:08 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_lstnew(int val)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = val;
	new->next = new;
	new->prev = new;
	return (new);
}

void	ft_lstadd_back(t_cll *lst, t_node *new)
{
	t_node	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (lst->head == NULL)
	{
		lst->head = new;
	}
	else
	{
		last = lst->head->prev;
		last->next = new;
		new->prev = last;
		lst->head->prev = new;
		new->next = lst->head;
	}
	lst->size++;
}

static long int	ft_num_builder(const char *nptr, long int nb)
{
	while ((*nptr >= '0' && *nptr <= '9'))
	{
		nb = nb * 10 + (*nptr - '0');
		nptr++;
	}
	if (*nptr != '\0')
		return (-1);
	else
		return (nb);
}

long int	ft_atoi(const char *nptr)
{
	long int	nb;
	int			neg;

	nb = 0;
	neg = 0;
	if (*nptr == '\0')
		return (0);
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	while (*nptr == '0')
		nptr++;
	if (*nptr == '-')
	{
		neg = 1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	nb = ft_num_builder(nptr, nb);
	if (nb == -1)
		return (2147483648);
	if (neg == 1)
		nb = -nb;
	return (nb);
}

void	ft_lstclear(t_cll *lst)
{
	t_node	*temp;
	int		i;

	temp = NULL;
	if (lst == NULL)
		return ;
	i = 0;
	while (i++ < lst->size)
	{
		temp = lst->head->next;
		free(lst->head);
		lst->head = temp;
	}
	lst = NULL;
}
