/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahino- <azahino-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:26:26 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/06/30 14:42:53 by azahino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_ignore(char c)
{
	if (((c >= 9) && (c <= 13)) || c == ' ')
		return (1);
	return (0);
}

int	ft_count_words(char const *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (ft_ignore(*s) > 0)
			s++;
		if (*s == '\0')
			return (count);
		while (ft_ignore(*s) == 0 && *s)
			s++;
		count++;
	}
	return (count);
}

static int	ft_count_letters(char *word)
{
	int	count;

	count = 0;
	while (ft_ignore(*word) > 0)
		word++;
	while (ft_ignore(*word) == 0)
	{
		if (*word == '\0')
			return (count);
		count++;
		word++;
	}
	return (count);
}

static char	*save_word(char **array, char const *s, int word_pos)
{
	int		num_letters;
	int		i;

	num_letters = ft_count_letters((char *)s);
	array[word_pos] = malloc((num_letters + 1) * sizeof(char));
	if (!array[word_pos])
	{
		ft_freeall(array, word_pos);
		return (NULL);
	}
	i = 0;
	while (ft_ignore(*s) > 0)
		s++;
	while (i < num_letters)
	{
		array[word_pos][i] = *s;
		s++;
		i++;
	}
	array[word_pos][i] = '\0';
	while (ft_ignore(*s) > 0)
		s++;
	return ((char *)s);
}

char	**ft_split(char const *s)
{
	char	**array;
	int		i;
	int		words;
	int		word_pos;

	if (!s)
		return (NULL);
	words = ft_count_words(s);
	array = malloc((words + 1) * sizeof(char *));
	word_pos = 0;
	if (!array)
	{
		ft_freeall(array, word_pos);
		return (NULL);
	}
	array[words] = NULL;
	i = 0;
	while (i < words)
	{
		s = save_word(array, s, word_pos++);
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