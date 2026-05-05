/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:16:49 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/04 11:22:22 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (c > 256)
		c = c - 256;
	while (*s)
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == c)
	{
		return ((char *)s);
	}
	return (NULL);
}

/*
#include <stdio.h>
int main()
{
	const char *str1 = "test";
	const char *str2 = "tst";
	int c = 101;
	
	printf("%s\n", ft_strchr(str1, c));
	printf("%s", ft_strchr(str2, c));
}
*/