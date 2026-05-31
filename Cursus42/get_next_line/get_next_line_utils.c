/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:22:16 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/29 13:29:59 by jrecio-t         ###   ########.fr       */
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

	if (s1 == NULL)
		return (ft_strdup(s2));
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

static void	loop(size_t length, char *str, const char *p)
{
	while (length > 0)
	{
		*str = *p;
		str++;
		p++;
		length--;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	const char	*p;
	char		*str;
	char		*result;
	size_t		slen;

	slen = ft_strlen(s);
	str = malloc(slen + 1);
	if (!str)
		return (NULL);
	result = str;
	p = s + start;
	loop(len, str, p);
	result[slen] = '\0';
	return (result);
}
