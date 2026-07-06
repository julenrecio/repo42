/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:18:41 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/06/22 15:51:40 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_character(int fd, char c)
{
	return (write(fd, &c, 1));
}

static int	ft_printf_string(int fd, char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (write(fd, "(null)", 6));
	while (*str)
	{
		count += write(fd, str, 1);
		str++;
	}
	return (count);
}

static int	ft_check_especifier(int fd, char const *format, va_list args)
{
	if (*format == 'c')
		return (ft_printf_character(fd, va_arg(args, int)));
	else if (*format == 'd' || *format == 'i')
		return (ft_printf_decimal(fd, va_arg(args, int)));
	else if (*format == 'f')
		return (ft_printf_float(fd, va_arg(args, double)));
	else if (*format == 'x')
		return (ft_printf_hex(fd, va_arg(args, unsigned int), 0));
	else if (*format == 'X')
		return (ft_printf_hex(fd, va_arg(args, unsigned int), 1));
	else if (*format == 'p')
		return (ft_printf_pointer(fd, (long int)va_arg(args, void *)));
	else if (*format == 'u')
		return (ft_printf_unsigned_decimal(fd, va_arg(args, unsigned int)));
	else if (*format == 's')
		return (ft_printf_string(fd, va_arg(args, char *)));
	else if (*format == '%')
		return (write(fd, "%", 1));
	else
		return (0);
}

int	ft_printf(int fd, const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_check_especifier(fd, format, args);
		}
		else
			count += write(fd, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>
int	main(void)
{
	int count1 = 0;
	int count2 = 0;
	int var = 0;;
	count1 = ft_printf("%c %s %p %d %i %u %x %X %%", 
	'a', "string", &var, 42, -42, 256, 1000, 1000);
	printf("\n");
	count2 = printf("%c %s %p %d %i %u %x %X %%", 
	'a', "string", &var, 42, -42, 256, 1000, 1000);
	printf("\n");
	printf("Bytes: %d\n", count1);
	printf("Bytes: %d\n", count2);
}
*/