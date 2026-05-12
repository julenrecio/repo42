/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:11:16 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/11 15:27:50 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}

/*
#include <fcntl.h>
int main()
{
	int fd = open("text.txt", O_WRONLY | O_CREAT, 0644);
	ft_putstr_fd("hello world", fd);
}
*/
