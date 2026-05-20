/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:35:13 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/13 16:28:13 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*prev;
	t_list	*head;
	t_list	*new_node;
	void	*content;

	head = NULL;
	prev = NULL;
	while (lst != NULL && f != NULL && del != NULL)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&head, del);
			return (NULL);
		}
		if (!head)
			head = new_node;
		else
			prev->next = new_node;
		prev = new_node;
		lst = lst->next;
	}
	return (head);
}

/*
void *f(void *content)
{
	char *str = (char *)content;
	str[0] = 'X';
	return ((void *)str);
}

void del(void *node)
{
	free(node);
}

#include <stdio.h>
int main()
{
	char content1[] = "string1";
	char content2[] = "string2";
	char content3[] = "string3";
	t_list *node1 = ft_lstnew(content1);
	t_list *node2 = ft_lstnew(content2);
	t_list *node3 = ft_lstnew(content3);
	t_list *lst = NULL;
	ft_lstadd_front(&lst, node1);
	ft_lstadd_front(&lst, node2);
	ft_lstadd_front(&lst, node3);

	t_list *temp1 = lst;

	while (temp1 != NULL)
	{
		printf("%s\n", (char *)temp1->content);
		temp1 = temp1->next;
	}
	
	temp1 = ft_lstmap(lst, f, del);

	while (temp1 != NULL)
	{
		printf("%s\n", (char *)temp1->content);
		temp1 = temp1->next;
	}
}
*/