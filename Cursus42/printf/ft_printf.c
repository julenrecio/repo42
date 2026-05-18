/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:18:41 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/18 17:41:05 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(char const *format, ...)
{
	va_list	args;
	char	*string;
	int		count;

	va_start(args, format);
	string = va_arg(args, char *);
	va_end(args);
	count = 0;
	while (*string)
	{
		write(1, string, 1);
		string++;
		count++;
	}
	return (count);
}

int	main(void)
{
	ft_printf("Imprimir un string: %s", "Hello");
	ft_printf("Imprimir un string: %s", "world");
	/*
	printf("%3$d, %1$d, %2$d", 2, 5, 1);
	printf("\n");
	printf("%03d", 1);
	printf("\n");
	printf("%03d", 100);
	printf("\n");
	printf("%#f", 3.14);
	printf("\n");
	printf("%#f", 42.42);
	printf("\n");
	printf("%*d, %*d", 0, 10, 10, 5);
	printf("\n");
	printf("%.*s", 3, "abcdef");
	printf("\n");
	printf("%.*f", 3, 42.4242);
	printf("\n");
	printf("%.3s", "abcdef");
	printf("\n");
	printf("%.3f", 42.4242);
	printf("\n");
	printf("%.4f", 42.4242);
	printf("\n");
	printf("%hhd", 'a');
	printf("\n");
	printf("%u", -10);
	printf("\n");
	printf("%o", 10);
	printf("\n");
	printf("%%");
	printf("\n"); 
	*/
}
