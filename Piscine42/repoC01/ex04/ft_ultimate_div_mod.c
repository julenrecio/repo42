/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:16:40 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/03/08 17:27:42 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	x;
	int	y;

	x = *a;
	y = *b;
	*a = x / y;
	*b = x % y;
}

/*
int main()
{
	int a;
	int b;
	
	a = 20;
	b = 5;

	printf("Number value: %d \n", a);
	printf("Number value: %d \n", b);

	ft_ultimate_div_mod(&a, &b);

	printf("Number value: %d \n", a);
	printf("Number value: %d \n", b);

	return (0);
}
*/