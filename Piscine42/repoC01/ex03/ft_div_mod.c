/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:22:18 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/03/08 16:22:30 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
int main()
{
	int a;
	int b;
	int *div;
	int *mod;

	a = 10;
	b = 3;
	div = &a;
	mod = &b;

	printf("Number value: %d \n", a);
	printf("Number value: %d \n", b);

	ft_div_mod(a, b, div, mod);

	printf("Number value: %d \n", a);
	printf("Number value: %d \n", b);

	return (0);
}
*/