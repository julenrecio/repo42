/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:32:48 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/13 16:30:23 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*aux(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

static char	*aux2(char const *s1, const char *word_end, size_t i)
{
	char	*str;

	str = malloc(i + 1);
	if (!str)
		return (0);
	while (s1 != word_end)
	{
		*str = *s1;
		str++;
		s1++;
	}
	*str = '\0';
	return (str - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*word_start;
	const char	*word_end;
	size_t		i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	word_start = s1;
	while (*s1)
		s1++;
	s1--;
	while (s1 >= word_start && ft_strchr(set, *s1))
		s1--;
	word_end = s1 + 1;
	if (word_end == word_start)
		return (aux());
	i = word_end - word_start;
	return (aux2(word_start, word_end, i));
}

/*
#include <stdio.h>
int main()
{
	printf("%s", ft_strtrim("abcHelloabc", "abc"));
}
*/
