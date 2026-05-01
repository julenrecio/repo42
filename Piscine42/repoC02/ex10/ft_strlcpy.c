/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:14:54 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/03/12 16:49:31 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	char			*start;

	i = 0;
	start = src;
	if (size > 0)
	{
		while (*src && i < size -1)
		{
			*dest = *src;
			dest++;
			src++;
			i++;
		}
		*dest = '\0';
	}
	i = 0;
	src = start;
	while (*src)
	{
		i++;
		src++;
	}
	return (i);
}

/*
#include <unistd.h>
int	main()
{
	int		src_size;
	char	src[8] = "palabra";
	char	dest[7] = "prueba";
	char	*ptr1 = dest;
	char	*ptr2 = src;
	char	*ptr3 = dest;
	char	c;

	src_size = ft_strlcpy(ptr1, ptr2, 7);
	c = src_size + '0';
	write(1, &c, 1);
	write(1, "\n", 1);
	while (*ptr3)
	{
		write(1, ptr3, 1);
		ptr3++;
	}
}
*/