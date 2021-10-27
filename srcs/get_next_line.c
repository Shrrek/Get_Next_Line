/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:44:31 by jperales          #+#    #+#             */
/*   Updated: 2021/10/27 17:49:56 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*bufer;
	int		bytes_read;
	char	*drawer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bufer = malloc(BUFFER_SIZE * sizeof(char));
	if (!bufer)
		return (NULL);
	bytes_read = read(fd, bufer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free (bufer);
		return (NULL);
	}
	bufer[bytes_read] = '\0';
	drawer = ft_strjoin(drawer, bufer);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	fd = open("prueba2.txt", O_RDONLY);
	while (i < 3)
	{
		line = get_next_line(fd);
		printf("Linea %02d: %s", i, line);
		i++;
	}
	free (line);
	return (0);
}
