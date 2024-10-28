/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:24:07 by antonimo          #+#    #+#             */
/*   Updated: 2024/10/28 14:25:07 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* void	arg_validation(int ac, char **av)
{
	if (ac == X)
	{
		map_validation(av);
	}
} */

void	map_validation(char *map)
{
	int			fd;
	char		*line;
	int			len;
	t_entities	entities;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	if (!line)
		exit(EXIT_FAILURE);
	validate_map_edges(&line);
	len = ft_strlen(line);
	while (line)
	{
		validate_line(&line, len);
		count_entities(line, &entities);
		line = get_next_line(fd);
	}
	check_entities(entities, &line);
}

bool	validate_line(char **line, int len)
{
	validate_body(line, len);
	validate_map_edges(line);
}

void	check_entities(t_entities entities, char **line)
{
	if (entities.player_counter != 1 || entities.exit_counter != 1
		|| entities.collectible_counter < 1)
	{
		free(line);
		exit(EXIT_FAILURE);
	}
}

void	count_entities(char *line, t_entities *entities)
{
	entities->player_counter += check_strchr(line, 'P');
	entities->exit_counter += check_strchr(line, 'E');
	entities->collectible_counter += check_strchr(line, 'C');
}

void	validate_body(char *line, int len)
{
	if (!check_len(line, len) || !map_body(line, '1'))
	{
		free(line);
		exit(EXIT_FAILURE);
	}
}

void	validate_map_edges(char **line)
{
	if (!&line || !all_chars_same(line, '1'))
	{
		free(&line);
		exit(EXIT_FAILURE);
	}
}

// Función que comprueba que todos los chr sean iguales
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

// Función que comprueba que la primera letra y la ultima sean el chr 'c'
bool	map_body(char *str, char c)
{
	int	len;

	len = (ft_strlen(str));
	if (str[0] == c)
	{
		if (str[--len] == c)
			return (true);
	}
	return (false);
}

// Si str tiene un len diferente al que le paso, false.
bool	check_len(char *str, int len)
{
	if (ft_strlen(str) != len)
		return (false);
	return (true);
}

// Función que cuenta cuantas coincidencias de 'c' hay en un str
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

// Función que devuelve True en caso de que solo exista 1 coincidencia de 'c' en str
bool	one_char_in_str(str, c)
{
	int	count;

	count = count_char_in_str(str, c);
	if (count != 1)
		return (false);
	return (true);
}
