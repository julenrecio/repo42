/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahino- <azahino-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 11:32:24 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/06/19 08:15:47 by azahino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_decimal(int fd, int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += write(fd, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		n = -n;
		count += write(fd, "-", 1);
	}
	if (n >= 10)
	{
		count += ft_printf_decimal(fd, n / 10);
	}
	n = (n % 10) + '0';
	count += write(fd, &n, 1);
	return (count);
}

int	ft_printf_unsigned_decimal(int fd, unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_printf_unsigned_decimal(fd, n / 10);
	}
	n = (n % 10) + '0';
	count += write(fd, &n, 1);
	return (count);
}
