/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:37:37 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/01 11:39:01 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}

/*
#include <stdio.h>
int main() {
	char csrc[] = "Word";
	char cdest[5];
	
	ft_memcpy(cdest, csrc, sizeof(csrc)); 
	printf("%s", cdest);
}
*/