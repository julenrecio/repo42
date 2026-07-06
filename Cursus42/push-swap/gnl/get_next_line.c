/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:50:26 by azahino-          #+#    #+#             */
/*   Updated: 2026/06/30 10:03:17 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_isjump(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_loop(char **stash)
{
	int		i;
	char	*new;
	char	*line;

	i = 0;
	while ((*stash)[i] != '\0')
	{
		if ((*stash)[i] == '\n')
		{
			line = ft_substr(*stash, 0, i + 1);
			new = ft_substr(*stash, i + 1, ft_strlen(*stash) - (i + 1));
			free(*stash);
			*stash = new;
			return (line);
		}
		i++;
	}
	return (NULL);
}

static char	*ft_eof(char **stash)
{
	char	*line;

	if (!*stash || !**stash)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	line = ft_strdup(*stash);
	free(*stash);
	*stash = NULL;
	return (line);
}

static ssize_t	ft_asigment(int fd, char **stash)
{
	char	*buf;
	char	*copy;
	ssize_t	byte;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	byte = read(fd, buf, BUFFER_SIZE);
	if (byte < 0)
	{
		free(buf);
		return (-1);
	}
	buf[byte] = '\0';
	copy = ft_gnl_strjoin(*stash, buf);
	free(buf);
	if (copy == NULL)
	{
		free(*stash);
		*stash = NULL;
		return (-1);
	}
	free(*stash);
	*stash = copy;
	return (byte);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	ssize_t		byte;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash && ft_isjump(stash))
		return (ft_loop(&stash));
	byte = 1;
	while (byte > 0)
	{
		byte = ft_asigment(fd, &stash);
		if (ft_isjump(stash))
			return (ft_loop(&stash));
	}
	if (byte == 0)
		return (ft_eof(&stash));
	if (byte < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	return (NULL);
}
