/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:21:46 by antonimo          #+#    #+#             */
/*   Updated: 2024/11/11 13:54:50 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_validation(t_game *game, char *map)
{
    char        *super_line;
    /* char        **lines; */
    /* t_coords    p_coords; */
    /* t_entities  entities; */
    
	if (ft_strncmp(ft_strrchr(map, '.'), ".ber", 5))
		error_msg("Error: not valid extension.");
    super_line = txt_to_line(map);
    game->map = ft_split(super_line, '\n');
    free(super_line);
    validate_edges(game->map);
    validate_body(game->map, &game->entities);
    game->player_pos = find_player(game->map);
    reachable_entities(game->map, game->entities, game->player_pos);
	map_dimension(game);
	/* printf("%d, %d\n", game->map_height, game->map_width); */
    free_matrix(game->map);
}

void	map_dimension(t_game *game)
{
	game->map_height = matrixlen(game->map);
	game->map_width = ft_strlen_gnl(game->map[0]);
}

char	*txt_to_line(char *txt)
{
	int		fd;
	char	*super_line;

	fd = open(txt, O_RDONLY);
	if (fd == -1)
		return (NULL);
	super_line = process_txt(fd);
	close(fd);
	return (super_line);
}

char	*process_txt(int fd)
{
	char	*super_line;
	char	*gnl_line;

	super_line = ft_strdup("");
	gnl_line = get_next_line(fd);
	if (!gnl_line)
	{
		free(super_line);
		error_msg("Error: converting text to line");
	}
	while (gnl_line)
	{
		super_line = gnl_cat(super_line, gnl_line);
		free(gnl_line);
		gnl_line = get_next_line(fd);
	}
	return (super_line);
}
