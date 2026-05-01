/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:50:00 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/03/08 18:02:20 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

/*
int main()
{
	int i = 0;
	char *str;
	str = "Texto de prueba";
	i = ft_strlen(str);
	printf("El número de caracteres es: %d", i);
	return (0);
}
*/