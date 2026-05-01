/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:03:34 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/03/11 11:37:38 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src, unsigned int n)
{
	char			*start;
	unsigned int	i;

	i = 0;
	start = dest;
	while (*src && i < n)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	while (i < n)
	{
		*dest = '\0';
		dest++;
		i++;
	}
	*dest = '\0';
	return (start);
}

/*
#include <unistd.h>
int	main (void)
{
	char	source[] = "source";
	char	destination[] = "destination";
	int	n;
	n = 8;
	write(1, ft_strcpy(destination, source, n), 1);
}
*/