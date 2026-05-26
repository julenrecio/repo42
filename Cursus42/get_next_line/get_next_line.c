/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:58:59 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/26 13:17:12 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	n;

	n = read(fd, buf, BUFFER_SIZE);
	buf[n] = '\0';
	write(1, buf, n);
	close(fd);
	exit(0);
}

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDWR | O_CREAT, 0777);
	get_next_line(fd);
}
