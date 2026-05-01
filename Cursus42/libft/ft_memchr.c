/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 11:35:59 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/04/27 11:13:57 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = s;
	while (n > 0)
	{
		if (*p == (unsigned char)c)
		{
			return ((void *)p);
		}
		p++;
		n--;
	}
	return (NULL);
}

/*
#include <stdio.h>
int main()
{
	printf("%s\n", (char *)ft_memchr("helloworlda", 97, 11));
	printf("%s\n", (char *)ft_memchr("helloworldabcde", 97, 11));
	printf("%s", (char *)ft_memchr("helloworlda", 97, 10));
	printf("%s", (char *)ft_memchr("helloworld", 97, 20));
}
*/