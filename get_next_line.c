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

char	*ft_set_buffer(int fd, char *buffer)
{
	char	*aux_buffer;
	ssize_t	read_value;

	aux_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!aux_buffer)
		return (0);
	read_value = 1;
	while (read_value != 0 && !ft_strchr(buffer, '\n'))
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

char	*ft_buffer_to_line(char *buffer)
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

char	*ft_next_line(char *buffer)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (buffer[i])
		line[j++] = buffer[++i];
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (buffer);
		buffer = NULL;
		return (0);
	}
	buffer = ft_set_buffer(fd, buffer);
	if (!buffer)
		return (0);
	line = ft_buffer_to_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}
