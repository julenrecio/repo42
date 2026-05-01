/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:03:56 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/03/12 13:07:30 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	char	*start;
	int		sig_mayus;

	start = str;
	while (*str)
	{
		if (*str >= 65 && *str <= 90)
			*str = *str + 32;
		str++;
	}
	sig_mayus = 1;
	str = start;
	while (*str)
	{
		if (sig_mayus)
		{
			*str = *str - 32;
			sig_mayus = 0;
		}
		if (*str == 32)
			sig_mayus = 1;
		str++;
	}
	return (start);
}

/*
#include <unistd.h>
int	main ()
{
	char	string[] = "esTO es uNa frAse";
	char	*ptr = string;
	char	*ptr2;

	ptr2 = ft_strcapitalize(ptr);
	while (*ptr2)
	{
		write(1, ptr2, 1);
		ptr2++;
	}
}
*/