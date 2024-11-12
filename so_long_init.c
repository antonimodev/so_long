/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:37:47 by antonimo          #+#    #+#             */
/*   Updated: 2024/11/12 12:43:04 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_mlx(t_game *game)
{
    int win_width;
    int win_height;

    win_height = game->map_height * TILE_SIZE;
    win_width = game->map_width * TILE_SIZE;
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        //liberar los datos de t_game
        error_msg("Error: mlx can't initialise");
    }
    game->win = mlx_new_window(game->mlx, win_height, win_width, "Window's name");
    if (!game->win)
    {
        //liberar los datos de t_game
        error_msg("Error: mlx can't create a window");
    }
}

void render_map(t_game *game)
{
    int x = 0;
    int y = 0;
    
    while (game->map[y])
    {
        printf("%d", game->map_width);
        x = 0;
        while (game->map[y][x])
        {
            /* printf("%d", game->map_width); */
           /*  printf("%s\n", game->map[y]);
            printf("%s", game->map[x]); */
            if (game->map[y][x] == WALL)
                mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == PLAYER)
                mlx_put_image_to_window(game->mlx, game->win, game->player_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == COIN)
                mlx_put_image_to_window(game->mlx, game->win, game->coin_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == EXIT)
                mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}
