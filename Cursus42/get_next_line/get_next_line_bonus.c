/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:27:41 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/10/12 16:31:45 by jrecio-t         ###   ########.fr       */
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
	static char	*stash[256];
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
		if (ft_strnchr(stash[fd]))
			return (free(buf), get_line(&stash[fd]));
		bytes = read(fd, buf, BUFFER_SIZE);
		if (check_bytes(bytes, &stash[fd], buf, &line))
			return (line);
		tmp = stash[fd];
		stash[fd] = ft_strjoin(stash[fd], buf);
		free(tmp);
	}
	return (NULL);
}

/*
# include <stdio.h>
# include <fcntl.h>
int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line1;
	char	*line2;
	char	*line3;

	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	fd3 = open("file3.txt", O_RDONLY);
	
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);
	
	while (line1 || line2 || line3)
	{
		if (line1)
		{
			printf("fd1: %s", line1);
			free(line1);
			line1 = get_next_line(fd1);
		}
		if (line2)
		{
			printf("fd2: %s", line2);
			free(line2);
			line2 = get_next_line(fd2);
		}
		if (line3)
		{
			printf("fd3: %s", line3);
			free(line3);
			line3 = get_next_line(fd3);
		}
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
*/
