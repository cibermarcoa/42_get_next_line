/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiaz-ca <mdiaz-ca@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:52:27 by mdiaz-ca          #+#    #+#             */
/*   Updated: 2023/03/28 19:58:19 by mdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buffertoline(char *buffer)
{
	char	*line;
	size_t	i;

	if (!buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}
/*
char	*ft_buffer(char *buffer)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (buffer[i])
		s[c++] = buffer[i++];
	s[c] = '\0';
	free(buffer);
	return (s);
}
*/

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	// find len of first line
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// if eol == \0 return NULL
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	// len of file - len of firstline + 1
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	// line == buffer
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}
char	*ft_setbuffer(int fd, char *buffer)
{
	char	*aux_buffer;
	ssize_t	read_value;

	if (!buffer)
		buffer = (char *)malloc(sizeof(char));
	aux_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer || !aux_buffer)
		return (0);
	read_value = 1;
	while (read_value != 0)
	{
		read_value = read(fd, aux_buffer, BUFFER_SIZE);	
		if (read_value == -1)
		{
			free(aux_buffer);
			return (0);
		}
		aux_buffer[read_value] = '\0';
		buffer = ft_strjoin(buffer, aux_buffer);
	}
	free(aux_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = NULL;
	buffer = ft_setbuffer(fd, buffer);
	if (!buffer)
		return (0);
	line = ft_buffertoline(buffer);
	buffer = ft_next(buffer);
	return (line);
}
