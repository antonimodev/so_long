/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:37:47 by antonimo          #+#    #+#             */
/*   Updated: 2024/11/11 13:46:43 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void init_game(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        error_msg("Error: mlx_init failed");

    game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE, game->map_height * TILE_SIZE, "so_long");
    if (!game->win)
        error_msg("Error: mlx_new_window failed");

    game->wall_img = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", &game->map_width, &game->map_height);
    game->player_img = mlx_xpm_file_to_image(game->mlx, "images/player.xpm", &game->map_width, &game->map_height);
    game->coin_img = mlx_xpm_file_to_image(game->mlx, "images/coin.xpm", &game->map_width, &game->map_height);
    game->exit_img = mlx_xpm_file_to_image(game->mlx, "images/exit.xpm", &game->map_width, &game->map_height);

    if (!game->wall_img || !game->player_img || !game->coin_img || !game->exit_img)
        error_msg("Error: mlx_xpm_file_to_image failed");
} *//* 

void render_map(t_game *game)
{
    int x, y;

    for (y = 0; y < game->map_height; y++)
    {
        for (x = 0; x < game->map_width; x++)
        {
            if (game->map[y][x] == WALL)
                mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == PLAYER)
                mlx_put_image_to_window(game->mlx, game->win, game->player_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == COIN)
                mlx_put_image_to_window(game->mlx, game->win, game->coin_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == EXIT)
                mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * TILE_SIZE, y * TILE_SIZE);
        }
    }
} */
