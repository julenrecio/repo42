/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:58:59 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/28 18:38:47 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*stash;
	char		*line;
	size_t		i;

	stash = malloc(1);
	line = malloc(1);
	buf[BUFFER_SIZE] = '\0';
	while (read(fd, buf, BUFFER_SIZE > 0))
	{
		stash = ft_strjoin(stash, buf);
		while (*stash)
		{
			if (*stash == '\n')
			{
				line = stash;
			}
			else
			{
				i++;
			}
		}	
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("file.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	close(fd);
}
