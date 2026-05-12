/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:40:11 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/11 16:43:39 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	n = (n % 10) + '0';
	write(fd, &n, 1);
}

/*
#include <fcntl.h>
int main()
{
	int nb = 2147483647;
	int fd = open("text.txt", O_WRONLY | O_CREAT, 0644);
	ft_putnbr_fd(nb, fd);
}
*/