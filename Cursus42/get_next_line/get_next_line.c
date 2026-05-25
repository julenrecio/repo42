/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:58:59 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/25 16:35:23 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd, int buffer_size)
{
	char	buf[buffer_size + 1];
	ssize_t	n;

	n = 0;
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	
	n = read(fd, buf, buffer_size);
	while (n > 0)
	{
		buf[n] = '\0';
		if ((write(STDOUT_FILENO, buf, n)) == -1)
		{
			perror("write");
			exit(1);
		}
	}
	close(fd);
	exit(0);
}

int	main()
{
	int		fd;

	fd = open("file.txt", O_RDWR | O_CREAT, 0777);
	get_next_line(fd, BUFFER_SIZE);
}
