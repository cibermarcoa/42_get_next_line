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

char	*ft_get_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (save[i])
		s[c++] = save[i++];
	s[c] = '\0';
	free(save);
	return (s);
}

char	ft_setbuffer(int fd, char *buffer)
{
	char	*aux_buffer;
	int	read_value;

	aux_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!aux_buffer)
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
	buffer = ft_setbuffer(fd, buffer);
	if (!buffer)
		return (0);
	line = ft_get_line;
	buffer = ft_save(save);
	return (line);
}
