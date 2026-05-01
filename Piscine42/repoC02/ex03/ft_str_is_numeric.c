/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:59:50 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/03/11 14:44:56 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	resultado;

	resultado = 1;
	while (*str)
	{
		if (!(*str >= 48 && *str <= 57))
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
	char 	*string = "0123";

	resultado = ft_str_is_numeric(string);
	c = resultado + '0';
	write(1, &c, 1);
}
*/