/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:18:41 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/20 17:38:05 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_character(char c)
{
	return (write(1, &c, 1));
}
/*
int	ft_printf_unsigned_hex(unsigned int i)
{
	return (0);
}

int	ft_printf_pointer(char *p)
{
	return (0);
}
*/

int	ft_printf_string(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}
	return (count);
}

int	ft_check_especifier(char const *format, va_list args)
{
	if (*format == 'c')
		return (ft_printf_character(va_arg(args, int)));
	else if (*format == 'd' || *format == 'i')
		return (ft_printf_decimal(va_arg(args, int)));
	//else if (*format == 'x' || *format == 'X')
		//return (ft_printf_unsigned_hex(va_arg(args, unsigned int)));
	//else if (*format == 'p')
		//return (ft_printf_pointer(va_arg(args, char *)));
	else if (*format == 'u')
		return (ft_printf_unsigned_decimal(va_arg(args, unsigned int)));
	else if (*format == 's')
		return (ft_printf_string(va_arg(args, char *)));
	else if (*format == '%')
		return (write(1, "%", 1));
	else
		return (0);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count = ft_check_especifier(format, args);
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>
int	main(void)
{
	int count = 0;
	count = ft_printf("Print a character: %c --> My printf\n", 'X');
	printf("Print a character: %c\n", 'X');
	printf("Number of bytes: %d\n", count);
	count = ft_printf("Print a string: %s --> My printf\n", "Hello world");
	printf("Print a string: %s\n", "Hello world");
	printf("Number of bytes: %d\n", count);
	count = ft_printf("Print an integer: %d --> My printf\n", 425785);
	printf("Print an integer: %d\n", 425785);
	printf("Number of bytes: %d\n", count);
	count = ft_printf("Print an unsigned integer: %u --> My printf\n", -1);
	printf("Print an unsigned integer: %u\n", -1);
	printf("Number of bytes: %u\n", count);
}
*/
