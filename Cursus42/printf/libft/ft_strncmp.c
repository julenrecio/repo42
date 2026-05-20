/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 11:04:55 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/13 16:30:11 by jrecio-t         ###   ########.fr       */
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
	printf("%d\n", ft_strncmp("helloworld", "hello", 5));
	printf("%d\n", ft_strncmp("helloworld", "hello36737", 5));
	printf("%d\n", ft_strncmp("helloworld", "hella", 5));
	printf("%d", ft_strncmp("helloworld", "hellp", 5));
}
*/