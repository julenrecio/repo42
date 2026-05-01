/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:48:12 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/03/07 17:21:04 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	g_c1;
char	g_c2;
char	g_c3;

void	increment(void)
{
	if (g_c1 == '9' && g_c2 == '9' && g_c3 == '9')
	{
		return ;
	}
	else if (g_c3 < '9')
	{
		g_c3++;
	}
	else if (g_c2 < '9' && g_c3 == '9')
	{
		g_c2++;
		g_c3 = '0';
	}
	else if (g_c1 < '9' && g_c2 == '9' && g_c3 == '9')
	{
		g_c1++;
		g_c2 = '0';
		g_c3 = '0';
	}
}

void	ft_print_comb(void)
{
	g_c1 = '0';
	g_c2 = '1';
	g_c3 = '2';
	while (!(g_c1 == '9' && g_c2 == '9' && g_c3 == '9'))
	{
		if (g_c1 < g_c2 && g_c2 < g_c3)
		{
			write(1, &g_c1, 1);
			write(1, &g_c2, 1);
			write(1, &g_c3, 1);
			if (!(g_c1 == '7' && g_c2 == '8' && g_c3 == '9'))
			{
				write(1, ", ", 2);
			}
		}
		increment();
	}
}

/*
int	main(void)
{
	ft_print_comb();
}
*/
