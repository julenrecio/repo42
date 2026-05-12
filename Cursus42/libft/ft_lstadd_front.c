/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 09:36:32 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/12 11:22:39 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*
#include <stdio.h>
int main()
{
	t_list *lst = NULL;
	void *content = "string";
	t_list *new = ft_lstnew(content);
	ft_lstadd_front(&lst, new);
	printf("%s", (char *)lst->content);
}
*/
