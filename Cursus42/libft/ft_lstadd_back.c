/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:01:08 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/12 13:38:16 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	else if (*lst == NULL && new != NULL)
	{
		*lst = new;
		return ;
	}
	else if (*lst != NULL && new != NULL)
	{
		last = ft_lstlast(*lst);
		last->next = new;
		new->next = NULL;
	}
}

/*
#include <stdio.h>
int main()
{
	t_list *lst = NULL;
	void *content = "string";
	t_list *new = ft_lstnew(content);
	ft_lstadd_back(&lst, new);
	printf("%s", (char *)lst->content);
}
*/