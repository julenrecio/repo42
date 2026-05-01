/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:36:59 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/03/09 12:23:45 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
		{
			i++;
		}
	}
}

/*
int main ()
{
	int array[10] = {2,5,3,1,4,0,6,8,9,7};
	int *tab = array;
	int size = 10;

	int i = 0;
    while (i < 10)
    {
        printf("Posicion %d del array: %d \n", i, tab[i]);
        i++;
    }

	printf("\n");

	ft_sort_int_tab(tab, size);

	i = 0;
    while (i < 10)
    {
        printf("Posicion %d del array: %d \n", i, tab[i]);
        i++;
    }
}
*/
