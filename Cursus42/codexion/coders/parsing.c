/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:54:09 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/11/04 17:26:26 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

long long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * (long long)1000 + tv.tv_usec / 1000);
}

bool	ft_atol(const char *str, long *result)
{
	char	*endptr;
	long	value;

	errno = 0;
	value = strtol(str, &endptr, 10);
	if (errno == ERANGE || str == endptr || *endptr != '\0')
		return (false);
	*result = value;
	return (true);
}

bool	parse_int(const char *str, int *result)
{
	long	value;

	if (!ft_atol(str, &value))
	{
		fprintf(stderr, "Error: Argument parsing error, "
			"non integer argument \n");
		return (false);
	}
	if (value < INT_MIN || value > INT_MAX)
	{
		fprintf(stderr, "Error: Argument parsing error, "
			"out of bounds integer \n");
		return (false);
	}
	*result = (int)value;
	return (true);
}
