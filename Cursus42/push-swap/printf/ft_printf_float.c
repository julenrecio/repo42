/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 12:21:35 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/06/23 09:09:06 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_float(int fd, double f)
{
	int			count;
	long long	temp;
	long long	dec_int;
	double		dec;

	count = 0;
	if (f < 0)
	{
		f = -f;
		count += write(fd, "-", 1);
	}
	temp = (long long)f;
	count += ft_printf_decimal(fd, temp);
	count += write(fd, ".", 1);
	dec = f - (double)temp;
	dec_int = (long long)((dec * 100.0) + 0.5);
	if (dec_int < 10)
		count += write(fd, "0", 1);
	count += ft_printf_decimal(fd, dec_int);
	return (count);
}
