/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omarquez <omarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 12:11:59 by omarquez          #+#    #+#             */
/*   Updated: 2026/03/01 16:42:32 by omarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	verifications(int x_count, int y_count, int x, int y)
{
	if (x_count == 1 && (y_count == 1 || y_count == y))
	{
		ft_putchar('A');
	}
	else if (x_count == x && (y_count == 1 || y_count == y))
	{
		ft_putchar('C');
	}
	else if ((y_count == 1 && x_count > 1)
		|| (y_count > 1 && x_count == 1)
		|| (y_count > 1 && x_count == x)
		|| (y_count == y && (x_count > 1 || x_count < x)))
	{
		ft_putchar('B');
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
	while (y_count <= y)
	{
		x_count = 1;
		while (x_count <= x)
		{
			verifications (x_count, y_count, x, y);
			x_count++;
		}
		ft_putchar('\n');
		y_count++;
	}
}
;