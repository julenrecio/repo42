/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahino- <azahino-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 13:22:33 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/06/19 08:15:11 by azahino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hex(int fd, unsigned int i, int mayus)
{
	int	count;

	count = 0;
	if (i >= 16)
		count += ft_printf_hex(fd, i / 16, mayus);
	if (i % 16 >= 10)
	{
		if (mayus)
		{
			i = (i % 16) + 65 - 10;
			count += write(fd, &i, 1);
		}
		else
		{
			i = (i % 16) + 97 - 10;
			count += write(fd, &i, 1);
		}
	}
	else
	{
		i = (i % 16) + 48;
		count += write(fd, &i, 1);
	}
	return (count);
}
