/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 18:03:56 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/03/09 12:32:54 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	izq;
	int	dcha;
	int	temp;

	izq = 0;
	dcha = size - 1;
	while (izq < dcha)
	{
		temp = tab[izq];
		tab[izq] = tab[dcha];
		tab[dcha] = temp;
		izq++;
		dcha--;
	}
}

/*
int main ()
{
    int *tab;
    int array[10];
    int i;
	int size;
    
    i = 0;
	size = 5;
    tab = array;
    while (i < size)
    {
        tab[i] = i;
        i++;
    }
	i = 0;
    while (i < size)
    {
        printf("Posicion %d del array: %d \n", i, tab[i]);
        i++;
    }
	
	printf("\n");
	
    ft_rev_int_tab(tab, i);

	i = 0;
    while (i < size)
    {
        printf("Posicion %d del array: %d \n", i, tab[i]);
        i++;
    }
}
*/
