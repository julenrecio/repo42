/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:17:16 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/21 16:19:15 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_pointer_aux(size_t i)
{
	int count;

	count = 0;
	if (i >= 16)
	{
		count += ft_printf_pointer_aux(i / 16);
	}
	if (i % 16 >= 10)
	{
		i = (i % 16) + 87;
		count += write(1, &i, 1);
	}
	else
	{
		i = (i % 16) + 48;
		count += write(1, &i, 1);
	}
	return (count);
}

int	ft_printf_pointer(size_t p)
{
	int count;

	count = 0;
	if (!p)
		return(write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	return (count + ft_printf_pointer_aux(p));
}