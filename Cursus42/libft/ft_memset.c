/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 12:45:15 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/04/21 15:22:10 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned long int	i;
	unsigned char		*p;

	i = 0;
	p = s;
	while (i < n)
	{
		*p = c;
		p++;
		i++;
	}
	return (s);
}

/*
#include <stdio.h>
int	main(void)
{
	char	str[20] = "hola   mundo";
	ft_memset(str + 4, '*', 3);
	printf("%s\n", str);
}
*/