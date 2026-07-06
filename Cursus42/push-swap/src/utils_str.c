/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:10:59 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/06/27 19:25:58 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if ((unsigned char)*s1 == (unsigned char)*s2)
		{
			s1++;
			s2++;
		}
		else if ((unsigned char)*s1 < (unsigned char)*s2)
		{
			return (-1);
		}
		else
		{
			return (1);
		}
	}
	return (0);
}

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

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*p = c;
		p++;
		n--;
	}
	return (s);
}

char	*ft_strdup(const char *s)
{
	int		size;
	char	*ptr;

	size = ft_strlen(s) + 1;
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

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!str)
		return (NULL);
	p = str;
	while (*s1)
	{
		*str = *s1;
		s1++;
		str++;
	}
	*str = ' ';
	str++;
	while (*s2)
	{
		*str = *s2;
		s2++;
		str++;
	}
	*str = '\0';
	return (p);
}
