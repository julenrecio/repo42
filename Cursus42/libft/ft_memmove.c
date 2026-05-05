/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:39:51 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/04 12:51:33 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	aux(char *d, const char *s, size_t n)
{
	if (d < s)
	{
		while (n > 0)
		{
			*d++ = *s++;
			n--;
		}
	}
	else
	{
		d = d + n;
		s = s + n;
		while (n > 0)
		{
			*--d = *--s;
			n--;
		}
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (d == NULL && s == NULL)
		return (NULL);
	aux(d, s, n);
	return (d);
}

/*
#include <stdio.h>
int main() { 
	char str1[] = "abcdef";
	char str2[] = "abcdef";
	printf("%s\n", (char *)ft_memmove(str1+1, str1, 4));
	printf("%s", (char *)ft_memmove(str2, str2+2, 4));
}
*/