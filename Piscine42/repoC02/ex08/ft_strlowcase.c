/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:38:57 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/03/12 13:00:02 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*start;

	start = str;
	while (*str)
	{
		if ((*str >= 65 && *str <= 90))
		{
			*str = *str + 32;
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

	ptr2 = ft_strlowcase(ptr);
	while (*ptr2)
	{
		write(1, ptr2, 1);
		ptr2++;
	}
}
*/
