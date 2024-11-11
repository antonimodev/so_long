/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:27:48 by antonimo          #+#    #+#             */
/*   Updated: 2024/11/11 13:26:53 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_edges(char **lines)
{
	if (!all_chars_same(lines[0], WALL)
		|| !all_chars_same(lines[(matrixlen(lines) - 1)], WALL))
		{
			free_matrix(lines);
			error_msg("Error: validate_edges: chr differs from '1'");
		}
}
void	validate_body(char **lines, t_entities *entities)
{
	int	len;
	int	i;

	entities->player_counter = 0;
	entities->coin_counter = 0; // Changed from collectible_counter to coin_counter
	entities->exit_counter = 0;
	len = ft_strlen_gnl(lines[0]);
	i = 1;
	while (lines[i])
	{
		count_entities(lines[i], entities);
		if (!validate_walls(lines[i]) || !validate_len(lines[i], len))
		{
			free_matrix(lines);
			error_msg("Error: validate_body: walls or len are incorrect!");
		}
		i++;
	}
	validate_entities(entities, lines);
}

bool	validate_walls(char *lines)
{
	if (lines[0] != WALL || lines[ft_strlen_gnl(lines) - 1] != WALL)
		return (false);
	return (true);
}

bool	validate_len(char *str, int len)
{
	if (ft_strlen_gnl(str) != len)
		return (false);
	return (true);
}

void	validate_entities(t_entities *entities, char **lines)
{
	if (entities->player_counter != 1
		|| entities->exit_counter != 1
		|| entities->coin_counter < 1) // Changed from collectible_counter to coin_counter
		{
			free_matrix(lines);
			error_msg("Error: validate_entities: wrong entities counter");
		}
}
