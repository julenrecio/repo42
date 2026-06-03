/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:58:59 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/06/03 14:51:03 by jrecio-t         ###   ########.fr       */
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
			return (line);
		}
		i++;
	}
	if (!(**stash))
		return (NULL);
	line = ft_substr(*stash, 0, i);
	free(*stash);
	*stash = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*stash;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		line = loop(buf, &stash);
		if (line)
		{
			free(buf);
			return (line);
		}
		else
		{
			free(buf);
			free(stash);
			stash = NULL;
			return(NULL);
		}
		if (bytes == 0 && stash)
		{
			line = loop(buf, &stash);
			if (line)
			{
				free(buf);
				return (line);
			}
		}

	}
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("file.txt", O_RDONLY);
	while((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	close(fd);
	return (0);
}
