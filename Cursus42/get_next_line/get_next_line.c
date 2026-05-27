/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:58:59 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/27 16:46:06 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*stash;
	size_t		byte;
	size_t		n;
	size_t		i;

	while ((byte = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		i = 0;
		while (i < byte)
		{
			if (buf[i] != '\n')
			{
				i++;
				n++;
			}
			else
				i = byte;
		}
	}
	stash = malloc(n + 1);
	return (stash);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("file.txt", O_RDWR | O_CREAT, 0777);
	str = get_next_line(fd);
	printf("%s", str);
	close(fd);
}
