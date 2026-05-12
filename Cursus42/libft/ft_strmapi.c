/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:59:19 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/11 12:40:05 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		index;
	int		len;
	char	*str;

	if (s == NULL || f == NULL)
		return (NULL);
	index = 0;
	len = ft_strlen(s);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (index < len)
	{
		*str = f(index, s[index]);
		str++;
		index++;
	}
	*str = '\0';
	str = str - len;
	return (str);
}

/*
char	ft_plus_index(unsigned int n, char c)
{
	return (c + n);
}

#include <stdio.h>
int main()
{
	const char *str = "abc";
	char *res = ft_strmapi(str, ft_plus_index);
	printf("%s", res);
}
*/