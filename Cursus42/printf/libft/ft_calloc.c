/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:18:27 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/13 16:10:04 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	bytes;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	bytes = nmemb * size;
	ptr = malloc(bytes);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_bzero(ptr, bytes);
	return (ptr);
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