/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:26:26 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/07 17:38:08 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
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

int	count_letters(char *word, char c)
{
	int	count;

	count = 0;
	while (*word != c)
	{
		count++;
		word++;
	}
	return (count);
}

void	save_word(char **array, char const *s, char c, int word_pos)
{
	char	*scopy;
	int		num_letters;
	int		i;

	scopy = ft_strchr(s, c);
	scopy++;
	num_letters = count_letters(scopy, c);
	array[word_pos] = malloc((num_letters + 1) * sizeof(char));
	i = 0;
	while (i < num_letters)
	{
		array[word_pos][i] = *s;
		s++;
		i++;
	}
	array[word_pos][i] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		words;
	int		word_pos;

	words = count_words(s, c);
	array = malloc((words + 1) * sizeof(char *));
	array[words] = NULL;
	i = 0;
	word_pos = 0;
	while (i < words)
	{
		save_word(array, s, c, word_pos);
		word_pos++;
		i++;
	}
	return (array);
}

/*
#include <stdio.h>
int main()
{	char **arreglo = ft_split("hello*hello*hello", '*');
	int	i = 0;
	while (i < sizeof(arreglo))
	{
		printf("%s", arreglo[i]);
		i++;
	}
}
*/