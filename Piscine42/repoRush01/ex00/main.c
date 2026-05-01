/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 11:23:50 by omarquez          #+#    #+#             */
/*   Updated: 2026/03/08 15:51:58 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	main(void)
{
	return (0);
}

int get_left_view(int pos, int array[])
{
	if (pos == 2)
	{
		return array[8];
	}
	else if (pos == 6)
	{
		return array[9];
	}
	else if (pos == 10)
	{
		return array[10];
	}
	else
	{
		return array[11];
	}
}

int get_right_view(int pos, int array[])
{
	if (pos == 2)
	{
		return array[12];
	}
	else if (pos == 6)
	{
		return array[13];
	}
	else if (pos == 10)
	{
		return array[14];
	}
	else
	{
		return array[15];
	}
}

int check_views(int pos, int num, int array[])
{
	int rightView = get_right_view(pos, array);
	int leftView = get_left_view(pos, array);
	int topView = array[2];
	int bottomView = array[6];
	
	if (pos == 2)
	{
		if (topView == 4)
		{
			if (num == 1)
			{
				return (0);
			}
		}
	}
}
