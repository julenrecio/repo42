/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 11:18:27 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/13 16:28:39 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = s1;
	p2 = s2;
	while (n > 0)
	{
		if (*p1 == *p2)
		{
			p1++;
			p2++;
			n--;
		}
		else if (*p1 < *p2)
		{
			return (-1);
		}
		else
		{
			return (1);
		}
	}
	return (0);
}

/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_memcmp("abcde", "abcde", 5));
	printf("%d\n", ft_memcmp("abcdef", "abcdee", 6));
	printf("%d\n", ft_memcmp("abcdee", "abcdef", 6));
}
*/
