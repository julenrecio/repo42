/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:30:59 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/11 15:38:50 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

/*
#include <fcntl.h>
int main()
{
	int fd = open("text.txt", O_WRONLY | O_CREAT, 0644);
	ft_putendl_fd("hello world", fd);
}
*/