/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 11:43:51 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/04/27 14:53:44 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len == 0)
	{
		return ((char *)big);
	}
	while (*big && len >= little_len)
	{
		if (*big == *little && ft_memcmp(little, big, little_len) == 0)
		{
			return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_strnstr("mundohola", "hola", 12));
	printf("%s\n", ft_strnstr("mundohola", "", 12));
	printf("%s", ft_strnstr("mundohol", "hola", 12));
}
*/
