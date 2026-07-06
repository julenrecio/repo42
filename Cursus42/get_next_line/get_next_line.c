/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:58:59 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/06/08 09:27:56 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_bytes(ssize_t bytes, char **stash, char *buf, char **line)
{
	if (bytes < 0)
	{
		free(buf);
		free(*stash);
		*stash = NULL;
		*line = NULL;
		return (1);
	}
	if (bytes == 0)
	{
		free(buf);
		if (*stash && **stash)
		{
			*line = *stash;
			*stash = NULL;
		}
		else
			*line = NULL;
		return (1);
	}
	buf[bytes] = '\0';
	return (0);
}

static char	*get_line(char **stash)
{
	char	*line;
	char	*tmp;
	int		i;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	line = ft_substr(*stash, 0, i);
	tmp = *stash;
	*stash = ft_substr(*stash, i, ft_strlen(*stash) - i);
	free(tmp);
	if (*stash && **stash == '\0')
	{
		free(*stash);
		*stash = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*buf;
	char		*line;
	static char	*stash;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = 1;
	line = NULL;
	while (bytes > 0)
	{
		if (ft_strnchr(stash))
			return (free(buf), get_line(&stash));
		bytes = read(fd, buf, BUFFER_SIZE);
		if (check_bytes(bytes, &stash, buf, &line))
			return (line);
		tmp = stash;
		stash = ft_strjoin(stash, buf);
		free(tmp);
	}
	return (NULL);
}
/*
# include <stdio.h>
# include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*str;

	fd = open("file.txt", O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	close(fd);
	return (0);
}
*/
