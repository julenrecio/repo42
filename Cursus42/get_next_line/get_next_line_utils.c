/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:22:16 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/28 11:59:48 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		s++;
		size++;
	}
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*p;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	p = str;
	while (*s1)
	{
		*str = *s1;
		s1++;
		str++;
	}
	while (*s2)
	{
		*str = *s2;
		s2++;
		str++;
	}
	*str = '\0';
	return (p);
}

char	*ft_strdup(const char *s)
{
	int		size;
	char	*ptr;

	size = strlen(s) + 1;
	ptr = malloc(size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (*s)
	{
		*ptr = *s;
		ptr++;
		s++;
	}
	*ptr = '\0';
	return (ptr - (size - 1));
}
