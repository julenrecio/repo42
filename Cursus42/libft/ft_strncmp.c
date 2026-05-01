/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 11:04:55 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/04/30 12:54:05 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if ((unsigned char)*s1 == (unsigned char)*s2)
		{
			s1++;
			s2++;
			n--;
		}
		else if ((unsigned char)*s1 < (unsigned char)*s2)
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
int	main(void)
{
	printf("%d\n", ft_strncmp("holamundo", "hola", 4));
	printf("%d\n", ft_strncmp("holamundo", "holb", 4));
	printf("%d\n", ft_strncmp("holamundo", "holA", 4));
	printf("%d", ft_strncmp("holamundo", "holA", 3));
}
*/
