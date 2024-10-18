/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:43:06 by antonimo          #+#    #+#             */
/*   Updated: 2024/10/17 13:01:26 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_line_remaining(char *stat_buff)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (stat_buff[i] && stat_buff[i] != '\n')
		i++;
	if (!stat_buff[i])
	{
		free(stat_buff);
		stat_buff = NULL;
		return (NULL);
	}
	line = ft_calloc((ft_strlen(stat_buff) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (stat_buff[i])
		line[j++] = stat_buff[i++];
	free(stat_buff);
	return (line);
}

char	*ft_line(char *stat_buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!stat_buff[i])
		return (NULL);
	while (stat_buff[i] && stat_buff[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (stat_buff[i] && stat_buff[i] != '\n')
	{
		line[i] = stat_buff[i];
		i++;
	}
	if (stat_buff[i] && stat_buff[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read_buffersize(int fd, char *stat_buff)
{
	char	*buffer;
	int		read_result;

	if (!stat_buff)
		stat_buff = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_result = 1;
	while (read_result > 0)
	{
		read_result = read(fd, buffer, BUFFER_SIZE);
		if (read_result < 0)
		{
			free(buffer);
			buffer = NULL;
			free(stat_buff);
			stat_buff = NULL;
			return (NULL);
		}
		buffer[read_result] = '\0';
		stat_buff = ft_strjoin(stat_buff, buffer);
		if (check_strchr(buffer, '\n') == 1)
			break ;
	}
	free(buffer);
	return (stat_buff);
}

char	*get_next_line(int fd)
{
	static char	*stat_buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stat_buff);
		stat_buff = NULL;
		return (NULL);
	}
	stat_buff = ft_read_buffersize(fd, stat_buff);
	if (ft_strlen(stat_buff) < 1)
	{
		free(stat_buff);
		stat_buff = NULL;
		return (NULL);
	}
	line = ft_line(stat_buff);
	stat_buff = ft_line_remaining(stat_buff);
	return (line);
}
