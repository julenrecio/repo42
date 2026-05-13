/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:22:04 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/13 15:24:51 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	avail_space;
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size <= dlen)
	{
		return (size + slen);
	}
	avail_space = size - (dlen + 1);
	while (*dst)
	{
		dst++;
	}
	while (*src && avail_space > 0)
	{
		*dst = *src;
		dst++;
		src++;
		avail_space--;
	}
	*dst = '\0';
	return (dlen + slen);
}

/*
#include <stdio.h>
int	main()
{
	int		length;
	char	src[] = "word1";
	char	dst[11] = "word2";
	char	*ptr1 = src;
	char	*ptr2 = dst;
	length = ft_strlcat(ptr2, ptr1, sizeof(dst));
	printf("%d\n", length);
	printf("%s", dst);
}
*/