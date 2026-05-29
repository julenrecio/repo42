/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:58:59 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/29 13:34:15 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*stash;
	char		*line;
	int			i;
	int			j;

	/*if (!stash)
	{
		stash = malloc(1);
		stash[0] = '\0';
	}*/
	buf[BUFFER_SIZE] = '\0';
	line = NULL;
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		i = 0;
		j = 0;
		stash = ft_strjoin(stash, buf);
		while (stash[i] != '\0')
		{
			if (stash[i] == '\n')
			{
				line = ft_substr(stash, 0, i + 1);
				stash = ft_substr(stash, i + 1, j);
				return (line);
			}
			else
			{
				i++;
			}
			j++;
		}
	}
	if (read(fd, buf, BUFFER_SIZE) == 0)
	{
		line = ft_strjoin(stash, buf);
		return (line);
	}
	else
		return (NULL);
}

int	main(void)
{
	int		fd;
	//char	*str;

	fd = open("file.txt", O_RDONLY);
	//while (str = get_next_line(fd))
	//	printf("%s", str);

	printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
			printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));

}
