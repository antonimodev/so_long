/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:21:46 by antonimo          #+#    #+#             */
/*   Updated: 2024/12/02 14:10:12 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_validation(t_game *game, char *map_file)
{
	validate_extension(map_file);
	set_map(game, map_file);
	validate_edges(*game);
	validate_body(*game, &game->entities);
	find_player(game->map, &game->player_pos);
	reachable_entities(*game, game->entities, game->player_pos);
	set_map_dimension(game);
	set_move_counter(game);
}

void	validate_extension(char *map)
{
	const char	*extension;

	extension = ft_strrchr(map, '.');
	if (!extension || ft_strncmp(extension, ".ber", 5) != 0
		|| ft_strncmp(map, "maps/", 5) != 0)
		error_msg("Error validate_extension: invalid extension or maps folder");
}

char	*txt_to_line(char *txt)
{
	int		fd;
	char	*super_line;

	fd = open(txt, O_RDONLY);
	if (fd == -1)
		error_msg("Error opening file: invalid file");
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
		error_msg("Error process_txt: converting text to line");
	}
	while (gnl_line)
	{
		super_line = gnl_cat(super_line, gnl_line);
		free(gnl_line);
		gnl_line = get_next_line(fd);
	}
	if (!check_line(super_line))
	{
		free(super_line);
		error_msg("Error check_line: there is an invalid character");
	}
	return (super_line);
}

bool	check_line(char *line)
{
	while (*line)
	{
		if (*line != PLAYER
			&& *line != COIN
			&& *line != EXIT
			&& *line != WALL
			&& *line != FLOOR
			&& *line != '\n')
			return (false);
		line++;
	}
	return (true);
}
