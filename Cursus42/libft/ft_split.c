/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:26:26 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/13 16:29:31 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			return (count);
		while (*s != c && *s)
			s++;
		count++;
	}
	return (count);
}

static int	ft_count_letters(char *word, char c)
{
	int	count;

	count = 0;
	while (*word == c)
		word++;
	while (*word != c)
	{
		if (*word == '\0')
			return (count);
		count++;
		word++;
	}
	return (count);
}

static void	freall(char **array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	*save_word(char **array, char const *s, char c, int word_pos)
{
	int		num_letters;
	int		i;

	num_letters = ft_count_letters((char *)s, c);
	array[word_pos] = malloc((num_letters + 1) * sizeof(char));
	if (!array[word_pos])
	{
		freall(array, word_pos);
		return (NULL);
	}
	i = 0;
	while (*s == c)
		s++;
	while (i < num_letters)
	{
		array[word_pos][i] = *s;
		s++;
		i++;
	}
	array[word_pos][i] = '\0';
	while (*s == c)
		s++;
	return ((char *)s);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		words;
	int		word_pos;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	array = malloc((words + 1) * sizeof(char *));
	word_pos = 0;
	if (!array)
	{
		freall(array, word_pos);
		return (NULL);
	}
	array[words] = NULL;
	i = 0;
	while (i < words)
	{
		s = save_word(array, s, c, word_pos++);
		if (!s)
			return (NULL);
		i++;
	}
	return (array);
}

/*
#include <stdio.h>
int main()
{	char **array = ft_split("   Sed non risus. Suspendisse   ", ' ');
	int	i = 0;
	while (array[i])
	{
		printf("%s", array[i]);
		i++;
	}
}
*/