/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:17:34 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/11 16:48:42 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_digits(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	count++;
	return (count);
}

static char	*main_loop(int digits, int n, char *str)
{
	int	next_digit;

	while (digits > 0)
	{
		next_digit = n % 10;
		n = n / 10;
		str--;
		*str = next_digit + '0';
		digits--;
	}
	return (str);
}

static char	*min_num(void)
{
	char	*str;

	str = malloc(12 * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, "-2147483648", 12);
	return (str);
}

char	*ft_itoa(int n)
{
	int		digits;
	int		neg;
	char	*str;

	if (n == -2147483648)
		return (min_num());
	digits = num_digits(n);
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	str = malloc((digits + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str = str + digits;
	*str = '\0';
	str = main_loop(digits, n, str);
	if (neg)
		*str = '-';
	return (str);
}

/*
#include <stdio.h>
int main()
{
	int nb = 4246757;
	printf("%s", ft_itoa(nb));
	
}
*/