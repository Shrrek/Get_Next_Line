/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:05:55 by jperales          #+#    #+#             */
/*   Updated: 2021/11/12 18:06:17 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)str);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (0);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (0);
	dest = malloc((ft_strlen(s1) + (ft_strlen(s2))) * sizeof(char) + 1);
	if (!dest)
		return (0);
	while (s1[++i] != '\0')
		dest[i] = s1[i];
	while (s2[j] != '\0')
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}
