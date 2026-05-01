/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omarquez <omarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:21:47 by omarquez          #+#    #+#             */
/*   Updated: 2026/03/01 12:40:32 by omarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	verifications(int y_count, int x_count, int x, int y)
{
	if ((y_count == 1 || y_count == y)
		&& (x_count == 1 || x_count == x))
	{
		ft_putchar('o');
	}
	else if ((x_count == 1 || x_count == x))
	{
		ft_putchar('|');
	}
	else if ((y_count == 1 || y_count == y))
	{
		ft_putchar('-');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	y_count;
	int	x_count;

	if (y < 1 || x < 1)
	{
		return ;
	}
	y_count = 1;
	while ((y_count <= y))
	{
		x_count = 1;
		while ((x_count <= x))
		{
			verifications(y_count, x_count, x, y);
			x_count ++;
		}
		ft_putchar('\n');
		y_count ++;
	}
}
;