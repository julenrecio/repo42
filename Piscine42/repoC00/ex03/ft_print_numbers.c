/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:17:19 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/03/07 17:20:54 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	int		x;
	char	c;

	x = 0;
	while (x <= 9)
	{
		c = x + '0';
		write(1, &c, 1);
		x++;
	}
}

/*
int	main(void)
{
	ft_print_numbers();
}
*/
