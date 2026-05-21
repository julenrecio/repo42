/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 13:22:33 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/21 16:55:57 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hex(unsigned int i, int mayus)
{
	int	count;

	count = 0;
	if (i >= 16)
		count += ft_printf_hex(i / 16, mayus);
	if (i % 16 >= 10)
	{
		if (mayus)
		{
			i = (i % 16) + 65 - 10;
			count += write(1, &i, 1);
		}
		else
		{
			i = (i % 16) + 97 - 10;
			count += write(1, &i, 1);
		}
	}
	else
	{
		i = (i % 16) + 48;
		count += write(1, &i, 1);
	}
	return (count);
}
