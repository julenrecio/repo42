/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 11:35:59 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/04 10:01:06 by jrecio-t         ###   ########.fr       */
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
	printf("%s", (char *)ft_memchr("helloworlda", 97, 10));
	printf("%s", (char *)ft_memchr("helloworld", 97, 20));
}
*/