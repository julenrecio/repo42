/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:22:16 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/06/01 17:02:22 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
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

static char	*ft_strdup(const char *s)
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
	size_t		length;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		length = 0;
	else if (len > slen - start)
		length = slen - start;
	else
		length = len;
	str = malloc(length + 1);
	if (!str)
		return (NULL);
	result = str;
	p = s + start;
	loop(length, str, p);
	result[length] = '\0';
	return (result);
}
