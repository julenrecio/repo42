/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:01:24 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/13 16:27:04 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*
#include <stdio.h>
int main(void)
{
	printf ("%d\n", ft_isascii(1));
	printf ("%d\n", ft_isascii(-1));
	printf ("%d\n", ft_isascii(127));
	printf ("%d\n", ft_isascii(128));
	printf ("%d\n", ft_isascii(200));
}
*/