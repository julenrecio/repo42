/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:24:59 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/07 17:42:26 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	loop(size_t length, char *str, const char *p)
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

/*
#include <stdio.h>
int main(void)
{
	char const *str = "string";
	char *result = ft_substr(str, 1, 3);
	printf("%s", result);
	free(result);
}
*/