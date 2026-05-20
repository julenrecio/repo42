/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 11:32:24 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/20 17:37:30 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_decimal(int n, int count)
{
	if (n == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		n = -n;
		count += write(1, "-", 1);
	}
	if (n >= 10)
	{
		count += ft_putnbr_decimal(n / 10, count);
	}
	n = (n % 10) + '0';
	count += write(1, &n, 1);
	return (count);
}

int	ft_putnbr_unsigned_decimal(unsigned int n, int count)
{
	if (n >= 10)
	{
		count += ft_putnbr_unsigned_decimal(n / 10, count);
	}
	n = (n % 10) + '0';
	count += write(1, &n, 1);
	return (count);
}

int	ft_printf_decimal(int i)
{
	return (ft_putnbr_decimal(i, 0));
}

int	ft_printf_unsigned_decimal(unsigned int i)
{
	return (ft_putnbr_unsigned_decimal(i, 0));
}
