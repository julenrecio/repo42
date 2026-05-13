/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:01:43 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/13 16:28:04 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL && f != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
void f(void *content)
{
	char *str = (char *)content;
	str[0] = 'X';
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
	
	ft_lstiter(lst, f);

	t_list *temp2 = lst;

	while (temp2 != NULL)
	{
		printf("%s\n", (char *)temp2->content);
		temp2 = temp2->next;
	}
}
*/