/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:24:07 by antonimo          #+#    #+#             */
/*   Updated: 2024/10/18 13:52:11 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* void	arg_validation(int ac, char **av)
{
	if (ac == X)
	{

	}
} */

void	map_validation(char	*map)
{
	int			fd;
	int			len;
	char		*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		//salirse porque el mapa está NULL
	if (!map_edges(line, '1'))
		//salirse porque el mapa no tiene bien los edges
	len = ft_strlen(line);
	while (line)
	{
		if (!check_len(line, len))
			//salir
		if (!map_body(line, '1'))
			//salir
		line = get_next_line(fd);
	}
	if (!map_edges(line, '1'))
		//salirse porque el mapa no tiene bien los edges
	printf("%d", len);
}

// Funcion que comprueba si el string está lleno del caracter c
bool	map_edges(char *str, char c)
{
	if (!all_chars_same(str, c))
		return (false);
	return (true);
}

bool	all_chars_same(char *str, char c)
{
	if (!str)
		return (false);
	while (*str)
	{
		if (*str != c)
			return (false);
		str++;
	}
	return (true);
}

bool	map_body(char *str, char c)
{
	int	len;

	len = (ft_strlen(str));
	if (str[0] != c)
	{
		if (len > 0 && str[len] == '\n')
			len--;
		if (str[len] != c)
			return (false);
	}
	return (true);
}

// Si str tiene un len diferente al que le paso, false.
bool	check_len(char *str, int len)
{
	if (ft_strlen(str) != len)
		return (false);
	return (true);
}

bool	count_collectibles(char *str, char c)
{
	return (count_char_in_str);
}

int	count_char_in_str(char *str, char c)
{
	int	res;

	res = 0;
	if (check_strchr(str, c))
	{
		while (*str)
		{
			if (*str == c)
				res++;
			str++;
		}
	}
	return (res);
}

bool	one_char_in_str(str, c)
{
	int	count;

	count = count_char_in_str(str, c);
	if (count != 1)
		return (false);
	return (true);
}
bool	player_exist(char *str, char c)
{
	return (one_char_in_str(str, c));
}

bool	exit_exist(char *str, char c)
{
	return (one_char_in_str(str, c));
}