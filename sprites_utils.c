/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:52:43 by antonimo          #+#    #+#             */
/*   Updated: 2024/11/25 14:27:32 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprite(t_game *game)
{
	game->floor_img = new_sprite(game, "textures/floor.xpm", "Floor");
	game->player_img = new_sprite(game, "textures/player.xpm", "Player");
	game->coin_img = new_sprite(game, "textures/coin.xpm", "Coin");
	game->exit_img = new_sprite(game, "textures/exit.xpm", "Exit");
	game->wall_img = new_sprite(game, "textures/wall.xpm", "Wall");
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
}

void	render_sprite(t_game *game, t_image sprite, int line, int column)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite.img, \
	column * TILE_SIZE, line * TILE_SIZE);
}

t_image	new_sprite(t_game *game, char *path, const char *entity)
{
	t_image	sprite;

	sprite.img = mlx_xpm_file_to_image(game->mlx, path, &sprite.x, &sprite.y);
	if (!sprite.img)
	{
		destroy_images(game);
		free_all(game);
		error_msg(ft_strjoin("Couldn't find a sprite of ", entity));
	}
	return (sprite);
}
