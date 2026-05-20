/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:26:58 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/13 16:29:58 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		src_size;

	src_size = ft_strlen(src);
	if (size == 0)
	{
		return (src_size);
	}
	i = 0;
	while (*src && i < size -1)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (src_size);
}

/*
#include <stdio.h>
int	main()
{
	int		src_size;
	char	src[] = "test";
	char	dest[5];
	char	*ptr1 = src;
	char	*ptr2 = dest;
	src_size = ft_strlcpy(ptr2, ptr1, 5);
	printf("%d\n", src_size);
	printf("%s", dest);
}
*/