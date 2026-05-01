/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:16:22 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/03/11 12:18:49 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	resultado;

	resultado = 1;
	while (*str)
	{
		if (!(*str >= 65 && *str <= 90))
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
	char 	*string = "ABC-DE";

	resultado = ft_str_is_uppercase(string);
	c = resultado + '0';
	write(1, &c, 1);
}
*/
