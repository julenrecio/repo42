/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:16:01 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/04/24 12:18:18 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
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
	printf ("%d\n", ft_isdigit(48));
	printf ("%d\n", ft_isdigit(57));
	printf ("%d\n", ft_isdigit(12));
}
*/
