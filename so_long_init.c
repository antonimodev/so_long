/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:37:47 by antonimo          #+#    #+#             */
/*   Updated: 2024/11/20 11:42:14 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_game *game)
{
	int	win_width;
	int	win_height;

	win_width = game->map_width * TILE_SIZE;
	win_height = game->map_height * TILE_SIZE;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_all(game);
		error_msg("Error: mlx can't initialise");
	}
	game->win = mlx_new_window(game->mlx, win_width, win_height, "so_long");
	if (!game->win)
	{
		free_all(game);
		error_msg("Error: mlx can't create a window");
	}
}

void	init_sprites(t_game *game)
{
	game->floor_img = new_sprite(game, "images/floor.xpm", "Floor");
	game->player_img = new_sprite(game, "images/player.xpm", "Player");
	game->coin_img = new_sprite(game, "images/coin.xpm", "Coin");
	game->exit_img = new_sprite(game, "images/exit.xpm", "Exit");
	game->wall_img = new_sprite(game, "images/wall.xpm", "Wall");
}

int	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map_copy[y])
	{
		x = 0;
		while (game->map_copy[y][x])
		{
			find_sprite(game, y, x);
			x++;
		}
		y++;
	}
	return (0);
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
