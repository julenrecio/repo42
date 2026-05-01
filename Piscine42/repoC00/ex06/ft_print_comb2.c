/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:59:56 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/03/11 15:02:59 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

char	g_n1c1;
char	g_n1c2;
char	g_n2c1;
char	g_n2c2;

bool	menor(void)
{
	if (g_n1c1 < g_n2c1)
	{
		return (true);
	}
	else if (g_n1c1 == g_n2c1 && g_n1c2 < g_n2c2)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

void	increment(void)
{
	if (g_n1c1 == '9' && g_n1c2 == '9' && g_n2c1 == '9' && g_n2c2 == '9')
		return ;
	else if (g_n2c2 < '9')
		g_n2c2++;
	else if (g_n2c1 < '9' && g_n2c2 == '9')
	{
		g_n2c1++;
		g_n2c2 = '0';
	}
	else if (g_n1c2 < '9' && g_n2c1 == '9' && g_n2c2 == '9')
	{
		g_n1c2++;
		g_n2c1 = '0';
		g_n2c2 = '0';
	}
	else if (g_n1c1 < '9' && g_n1c2 == '9' && g_n2c1 == '9' && g_n2c2 == '9')
	{
		g_n1c1++;
		g_n1c2 = '0';
		g_n2c1 = '0';
		g_n2c2 = '0';
	}
}

void	ft_print_comb2(void)
{
	g_n1c1 = '0';
	g_n1c2 = '0';
	g_n2c1 = '0';
	g_n2c2 = '1';
	while (!(g_n1c1 == '9' && g_n1c2 == '9' && g_n2c1 == '9' && g_n2c2 == '9'))
	{
		if (menor())
		{
			write(1, &g_n1c1, 1);
			write(1, &g_n1c2, 1);
			write(1, " ", 1);
			write(1, &g_n2c1, 1);
			write(1, &g_n2c2, 1);
			if (!(g_n1c1 == '9' && g_n1c2 == '8'
					&& g_n2c1 == '9' && g_n2c2 == '9'))
			{
				write(1, ", ", 2);
			}
		}
		increment();
	}
}

int	main(void)
{
	ft_print_comb2();
}
