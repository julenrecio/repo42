/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:55:19 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/04 12:51:44 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_builder(const char *nptr, int nb)
{
	while ((*nptr >= '0' && *nptr <= '9'))
	{
		nb = nb * 10 + (*nptr - '0');
		nptr++;
	}
	return (nb);
}

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	neg;

	nb = 0;
	neg = 0;
	if (*nptr == '\0')
		return (0);
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	while (*nptr == '0')
		nptr++;
	if (*nptr == '-')
	{
		neg = 1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	nb = num_builder(nptr, nb);
	if (neg == 1)
		nb = -nb;
	return (nb);
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_atoi(""));
	printf("%d\n", ft_atoi("0"));
	printf("%d\n", ft_atoi("42"));
	printf("%d\n", ft_atoi("-42"));
	printf("%d\n", ft_atoi("20547468"));
	printf("%d\n", ft_atoi("02547468"));
	printf("%d\n", ft_atoi("00047468"));
}
*/