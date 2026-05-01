/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:38:31 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/04/23 11:59:34 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		s++;
		size++;
	}
	return (size);
}

/*
#include <stdio.h>
int main(void)
{
	const char *s = "palabra";
	printf ("%lu\n", ft_strlen(s));
}
*/