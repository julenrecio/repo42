/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:41:41 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/03/08 16:18:06 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

/*
int	main(void)
{
	int	a;
	int	b;

	a = 10;
	b = 20;

	printf("Number value: %d \n", a);
	printf("Number value: %d \n", b);
	
	ft_swap(&a, &b);

	printf("Number value: %d \n", a);
	printf("Number value: %d \n", b);
}
*/
