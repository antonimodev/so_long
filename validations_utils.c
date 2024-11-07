/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:38:27 by antonimo          #+#    #+#             */
/*   Updated: 2024/11/07 13:45:26 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_entities(char *line, t_entities *entities)
{
	entities->player_counter += count_char_in_str(line, PLAYER);
	entities->exit_counter += count_char_in_str(line, EXIT);
	entities->collectible_counter += count_char_in_str(line, COIN);
}

// Concat strings freeing s1
char	*gnl_cat(char *s1, char *s2)
{
	char	*super_line;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	else if (s1 && !s2)
		return (s1);
	super_line = ft_calloc_gnl((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1), sizeof(char));
	i = 0;
	while (s1[i])
	{
		super_line[i] = s1[i];
		i++;
	}
	j = 0;
	while(!s1[i] && s2[j])
	{
		super_line[i + j] = s2[j];
		j++;
	}
	super_line[i + j] = '\0';
	free(s1);
	return (super_line);
}

//ft para localizar player

t_coords	find_player(char **map)
{
	t_coords	player_coords;

    player_coords.x = 1;
    player_coords.y = 1;
    while (map[player_coords.x])
    {
        while (map[player_coords.x][player_coords.y])
        {
            if (map[player_coords.x][player_coords.y] == PLAYER)
                flag = true;
            player_coords.y++;
        }
        player_coords.x++;
        player_coords.y = 1;
    }
    free_matrix(map);
    error_msg("Error: player not found");
}