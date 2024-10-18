/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:38:19 by antonimo          #+#    #+#             */
/*   Updated: 2024/10/17 12:58:32 by antonimo         ###   ########.fr       */
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
		stat_buff = ft_strjoin_gnl(stat_buff, buffer);
		if (check_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stat_buff);
}

char	*get_next_line(int fd)
{
	static char	*stat_buff[1024];
	char		*line;

	if (fd > 1024)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stat_buff[fd]);
		stat_buff[fd] = NULL;
		return (NULL);
	}
	stat_buff[fd] = ft_read_buffersize(fd, stat_buff[fd]);
	if (ft_strlen(stat_buff[fd]) < 1)
	{
		free(stat_buff[fd]);
		stat_buff[fd] = NULL;
		return (NULL);
	}
	line = ft_line(stat_buff[fd]);
	stat_buff[fd] = ft_line_remaining(stat_buff[fd]);
	return (line);
}
