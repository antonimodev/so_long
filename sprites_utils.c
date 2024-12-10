/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:52:43 by antonimo          #+#    #+#             */
/*   Updated: 2024/12/10 11:07:18 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprite(t_game *game)
{
	game->floor_img = new_sprite(game, "textures/floor.xpm");
	game->player_img = new_sprite(game, "textures/player.xpm");
	game->on_exit_img = new_sprite(game, "textures/on_exit.xpm");
	game->coin_img = new_sprite(game, "textures/coin.xpm");
	game->exit_img = new_sprite(game, "textures/exit.xpm");
	game->wall_img = new_sprite(game, "textures/wall.xpm");
}

void	find_sprite(t_game *game, int y, int x)
{
	char	coords;

	coords = game->map_copy[y][x];
	if (coords == WALL)
		render_sprite(game, game->wall_img, y, x);
	else if (coords == FLOOR)
		render_sprite(game, game->floor_img, y, x);
	else if (coords == COIN)
		render_sprite(game, game->coin_img, y, x);
	else if (coords == EXIT)
		render_sprite(game, game->exit_img, y, x);
	else if (coords == PLAYER)
		render_sprite(game, game->player_img, y, x);
	else if (coords == ON_EXIT)
		render_sprite(game, game->on_exit_img, y, x);
}

void	render_sprite(t_game *game, t_image sprite, int line, int column)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite.img, \
	column * TILE_SIZE, line * TILE_SIZE);
}

t_image	new_sprite(t_game *game, char *path)
{
	t_image	sprite;

	sprite.img = mlx_xpm_file_to_image(game->mlx, path, &sprite.x, &sprite.y);
	if (!sprite.img)
	{
		free_all(game);
		error_msg("Error new_sprite: not valid sprite");
	}
	return (sprite);
}
