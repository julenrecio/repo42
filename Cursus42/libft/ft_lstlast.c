/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:48:25 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/12 12:11:06 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp != NULL && temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}

/*
#include <stdio.h>
int main()
{
	void *content1 = "string1";
	void *content2 = "string2";
	void *content3 = "string3";
	t_list *node1 = ft_lstnew(content1);
	t_list *node2 = ft_lstnew(content2);
	t_list *node3 = ft_lstnew(content3);
	t_list *lst = NULL;
	ft_lstadd_front(&lst, node1);
	ft_lstadd_front(&lst, node2);
	ft_lstadd_front(&lst, node3);
	printf("%s", (char *)ft_lstlast(lst)->content);
}
*/