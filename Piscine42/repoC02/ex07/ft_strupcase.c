/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:56:02 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/03/12 12:59:52 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*start;

	start = str;
	while (*str)
	{
		if ((*str >= 97 && *str <= 122))
		{
			*str = *str - 32;
		}
		str++;
	}
	return (start);
}

/*
#include <unistd.h>
int	main()
{
	char	string[] = "ueJg335ab";
	char	*ptr = string;
	char	*ptr2;

	ptr2 = ft_strupcase(ptr);
	while (*ptr2)
	{
		write(1, ptr2, 1);
		ptr2++;
	}
}
*/