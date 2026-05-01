/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:39:51 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/04/30 17:31:10 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	aux(char *d, const char *s, size_t n)
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

	d = (char *)dest;
	s = (const char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	aux(d, s, n);
	return (dest);
}

/*
#include <stdio.h>
int main() { 
	char src[100] = "PalabraDePrueba";

	ft_memmove(src+7, src, ft_strlen(src)+1); 
	printf("%s", src); 
	return 0; 
}
*/