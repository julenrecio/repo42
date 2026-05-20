/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:04:37 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/13 16:30:18 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = NULL;
	while (c > 256)
		c = c - 256;
	while (*s)
	{
		if (*s == c)
		{
			p = (char *)s;
		}
		s++;
	}
	if (*s == c)
		p = (char *)s;
	if (p != NULL)
		return (p);
	else
		return (NULL);
}

/*
#include <stdio.h>
int main()
{
	const char *str1 = "abbbabb";
	const char *str2 = "\0";
	int c1 = 'a';
	int c2 = '0';
	printf("%s\n", ft_strrchr(str1, c1));
	printf("%s", ft_strrchr(str2, c2));
}
*/