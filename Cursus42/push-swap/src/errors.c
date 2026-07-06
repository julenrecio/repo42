/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:35:02 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/06/27 19:26:07 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_error(char *arg, t_mode *mode_p, t_mode mode, size_t len)
{
	int	count;

	count = 0;
	if (ft_strlen(arg) == len)
	{
		*mode_p = mode;
		count++;
	}
	else
		ft_show_error();
	return (count);
}

void	ft_show_error(void)
{
	ft_printf(2, "Error\n");
	exit(2);
}
