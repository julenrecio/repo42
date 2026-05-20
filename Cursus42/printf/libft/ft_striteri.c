/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 12:49:57 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/13 16:29:43 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		index;
	int		len;

	if (s != NULL && f != NULL)
	{
		index = 0;
		len = ft_strlen(s);
		while (index < len)
		{
			f(index, &(s[index]));
			index++;
		}
	}
}

/*
void	ft_plus_index(unsigned int n, char* address)
{
	*address = 'A' + n;
}

#include <stdio.h>
int main()
{
	char str[] = "abc";
	ft_striteri(str, ft_plus_index);
	printf("%s", str);
}
*/