/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:20:01 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/03/11 12:38:25 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	resultado;

	resultado = 1;
	while (*str)
	{
		if (!(*str >= 32 && *str <= 126))
		{
			resultado = 0;
		}
		str++;
	}
	return (resultado);
}

/*
#include <unistd.h>
int	main ()
{
	int		resultado;
	char	c;
	char 	*string = "|@#~{[efwg1546]}";

	resultado = ft_str_is_uppercase(string);
	c = resultado + '0';
	write(1, &c, 1);
}
*/