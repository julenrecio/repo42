/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 12:48:33 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/04/30 17:22:19 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		slen;
	char	*ptr;

	slen = ft_strlen(s) + 1;
	ptr = malloc(slen);
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
	return (ptr - (slen - 1));
}

/*
#include <stdio.h>
int main()
{
	const char *s = "helloworld";
	printf("%s", ft_strdup(s));
}
*/