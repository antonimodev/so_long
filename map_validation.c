/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:21:46 by antonimo          #+#    #+#             */
/*   Updated: 2024/11/12 11:04:42 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_validation(t_game *game, char *map_file)
{    
	/* printf("%s\n", game->map[0]); */
	validate_extension(map_file);
    set_map(game, map_file);
    validate_edges(game->map);
    validate_body(game->map, &game->entities);
    find_player(game->map, &game->player_pos);
    reachable_entities(game->map, game->entities, game->player_pos);
	set_map_dimension(game);
    /* free_matrix(game->map); */
}

void	validate_extension(char *map)
{
	if (ft_strncmp(ft_strrchr(map, '.'), ".ber", 5))
		error_msg("Error: not valid extension.");
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
