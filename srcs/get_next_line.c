/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:44:31 by jperales          #+#    #+#             */
/*   Updated: 2021/11/09 18:59:33 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/get_next_line.h"

char	*ft_new_store(char *store)
{
	size_t	i;
	char	*dest;
	size_t	j;

	i = 0;
	while (store[i] != '\0' && store[i] != '\n')
		i++;
	j = ft_strlen (store) - i;
	dest = malloc(sizeof(char) * (j + 1)); 
	if (!dest)
		return (NULL);
	j  = 0;
	i++;
	while (store[i])
	{
		dest[j] = store[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	free(store);
	return (dest);
}

char	*ft_get_line(char *store)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!store[i])
		return (NULL);
	while (store[i] != '\0' && store[i] != '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 2));
	if (!dest)
		return (NULL);
	i = 0;
	while (store[i] != '\n' && store[i])
	{
		dest[i] = store[i];
		i++;
	}
	if (store[i] == '\n')
	{
		dest[i] = store[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			bytes_read;
	static char	*store;
	char		*line;

	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(store, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		store = ft_strjoin(store, buffer);
	}
	free(buffer);
	if (!store)
		return (NULL);
	line = ft_get_line(store);
	store = ft_new_store(store);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	fd = open("prueba.txt", O_RDONLY);
	while (i < 8)
	{
		line = get_next_line(fd);
		printf("Linea %02d: %s", i, line);
		i++;
		free(line);
	}
	close(fd);
	return (0);
}*/
