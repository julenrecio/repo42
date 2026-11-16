/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:54:09 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/16 12:24:10 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

long long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * (long long)1000 + tv.tv_usec / 1000);
}

static bool	ft_atol(const char *str, long *result)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	if (!(*str >= '0' && *str <= '9'))
		return (false);
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str++ - '0');
		if ((sign == 1 && num > 2147483647)
			|| (sign == -1 && - num < -2147483648))
			return (false);
	}
	if (*str)
		return (false);
	*result = num * sign;
	return (true);
}

bool	parse_int(const char *str, int *result)
{
	long	value;

	if (!ft_atol(str, &value))
	{
		fprintf(stderr, "Error: Argument parsing error, "
			"non integer or invalid integer argument\n");
		return (false);
	}
	*result = (int)value;
	return (true);
}
