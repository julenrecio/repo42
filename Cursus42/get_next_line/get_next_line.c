/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:58:59 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/06/06 19:30:04 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char **stash)
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
	ssize_t 	bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		if (ft_strnchr(stash))
		{
			line = get_line(&stash);
			free(buf);
			return (line);
		}
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf);
			free(stash);
			stash = NULL;
			return (NULL);
		}
		if (bytes == 0)
		{
			free(buf);
			if (stash && *stash)
			{
				line = stash;
				stash = NULL;
				return (line);
			}
			return (NULL);
		}
		buf[bytes] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash, buf);
		free(tmp);
	}
	free(buf);
	return (NULL);
}
/*
int	main(void)
{
	int		fd;
	char	*str;

	fd = open("file.txt", O_RDONLY);
	while((str = get_next_line(fd)))
	{
		printf("[%s]", str);
		free(str);
	}
	close(fd);
	return (0);
}
*/
