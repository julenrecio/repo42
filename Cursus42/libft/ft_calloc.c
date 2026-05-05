/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:18:27 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/04 09:49:45 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	bytes;

	bytes = nmemb * size;
	if (bytes == 0)
	{
		return (NULL);
	}
	ptr = malloc(bytes);
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (bytes > 0)
	{
		*ptr = '\0';
		ptr++;
		bytes--;
	}
	return ((void *)(ptr - (nmemb * size)));
}

/*
#include <stdio.h>
int main()
{
	char *p = ft_calloc(10, sizeof(char));
	char *end = p + 10;
	while (p < end)
	{
		printf("%d ", *p);
		p++;
	}
}
*/