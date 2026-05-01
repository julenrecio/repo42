/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:22:03 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/03/11 11:49:57 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	resultado;

	resultado = 1;
	while (*str)
	{
		if (!((*str >= 65 && *str <= 90) || (*str >= 97 && *str <= 122)))
		{
			resultado = 0;
		}
		str++;
	}
	return (resultado);
}

/*
#include <unistd.h>
int main() 
{
	int resultado;
	char *str = "Hello World";
	char c = ft_str_is_alpha(str) + '0';
	write(1, &c, 1);
	return (0);
}
*/
