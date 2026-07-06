/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahino- <azahino-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:17:16 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/06/19 08:16:27 by azahino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_pointer_aux(int fd, size_t i)
{
	int	count;

	count = 0;
	if (i >= 16)
	{
		count += ft_printf_pointer_aux(fd, i / 16);
	}
	if (i % 16 >= 10)
	{
		i = (i % 16) + 87;
		count += write(fd, &i, 1);
	}
	else
	{
		i = (i % 16) + 48;
		count += write(fd, &i, 1);
	}
	return (count);
}

int	ft_printf_pointer(int fd, size_t p)
{
	int	count;

	count = 0;
	if (!p)
		return (write(1, "(nil)", 5));
	count += write(fd, "0x", 2);
	return (count + ft_printf_pointer_aux(fd, p));
}
