/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:58:59 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/06/02 17:58:48 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*loop(char *buf, char **stash)
{
	char		*tmp;
	char		*line;
	int			i;

	i = 0;
	tmp = *stash;
	*stash = ft_strjoin(*stash, buf);
	free(tmp);
	while ((*stash)[i] != '\0')
	{
		if ((*stash)[i] == '\n')
		{
			tmp = *stash;
			line = ft_substr(*stash, 0, i + 1);
			*stash = ft_substr(*stash, i + 1, ft_strlen(*stash) - (i + 1));
			free(tmp);
			if (**stash == '\0')
			{
				free(*stash);
				*stash = NULL;
			}
			return (line);
		}
		i++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*stash;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes < 0)
	{
		free(buf);
		return (NULL);
	}
	while (bytes > 0)
	{
		buf[bytes] = '\0';
		line = loop(buf, &stash);
		if (line)
		{
			free(buf);
			return (line);
		}		
		bytes = read(fd, buf, BUFFER_SIZE);
	}
	if (bytes == 0 && stash && *stash)
	{
		free(buf);
		line = stash;
		stash = NULL;
		return (line);
	}
	if (buf)
		free(buf);
	return (NULL);
}
/*
int	main(void)
{
	int		fd;
	char	*str;

	fd = open("file.txt", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}
}
*/

