/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:08:27 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/03/11 12:14:58 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	resultado;

	resultado = 1;
	while (*str)
	{
		if (!(*str >= 97 && *str <= 122))
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
	char 	*string = "abc?de";

	resultado = ft_str_is_lowercase(string);
	c = resultado + '0';
	write(1, &c, 1);
}
*/