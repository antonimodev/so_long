/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:38:12 by antonimo          #+#    #+#             */
/*   Updated: 2024/10/17 13:02:00 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		len;
	char	*str;
	int		i;
	int		j;

	len = (ft_strlen(s1) + ft_strlen(s2));
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[(i + j)] = '\0';
	free(s1);
	return (str);
}

int	check_strchr(char *str, char chr)
{
	int	i;

	i = 0;
	if (chr == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			return (1);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t size, size_t type)
{
	char	*str;
	size_t	i;

	str = (malloc(size * type));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < (size * type))
		str[i++] = 0;
	return (str);
}
