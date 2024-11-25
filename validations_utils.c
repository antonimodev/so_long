/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:38:27 by antonimo          #+#    #+#             */
/*   Updated: 2024/11/25 13:47:21 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_entities(char *line, t_entities *entities)
{
	entities->player_counter += count_char_in_str(line, PLAYER);
	entities->exit_counter += count_char_in_str(line, EXIT);
	entities->coin_counter += count_char_in_str(line, COIN);
}

void	find_player(char **map, t_coords *player_pos)
{
	player_pos->x = 1;
	player_pos->y = 1;
	while (map[player_pos->x])
	{
		while (map[player_pos->x][player_pos->y])
		{
			if (map[player_pos->x][player_pos->y] == PLAYER)
				return ;
			player_pos->y++;
		}
		player_pos->y = 1;
		player_pos->x++;
	}
	free_matrix(map);
	error_msg("Error: player not found");
}

void	flood_fill(int x, int y, t_entities *entities, char **map)
{
	if (!map[x] || !map[x][y])
		return ;
	if (map[x][y] == WALL || map[x][y] == VISITED)
		return ;
	if (map[x][y] == COIN)
		entities->coin_counter--;
	if (map[x][y] == EXIT)
		entities->exit_counter++;
	map[x][y] = VISITED;
	flood_fill(x + 1, y, entities, map);
	flood_fill(x - 1, y, entities, map);
	flood_fill(x, y + 1, entities, map);
	flood_fill(x, y - 1, entities, map);
}

void	reachable_entities(char **lines, t_entities entities, t_coords p_coords)
{
	flood_fill(p_coords.x, p_coords.y, &entities, lines);
	if (entities.coin_counter > 0 || entities.exit_counter != 2)
	{
		free_matrix(lines);
		error_msg("Error: No valid exit found or coins remaining");
	}
}

char	*gnl_cat(char *s1, char *s2)
{
	char	*super_line;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	else if (s1 && !s2)
		return (s1);
	super_line = ft_calloc_gnl((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1), \
	sizeof(char));
	i = 0;
	while (s1[i])
	{
		super_line[i] = s1[i];
		i++;
	}
	j = 0;
	while (!s1[i] && s2[j])
	{
		super_line[i + j] = s2[j];
		j++;
	}
	super_line[i + j] = '\0';
	free(s1);
	return (super_line);
}
