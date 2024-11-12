/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:37:47 by antonimo          #+#    #+#             */
/*   Updated: 2024/11/12 13:45:14 by antonimo         ###   ########.fr       */
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

// Función para inicializar un sprite y así poder trabajar con él.
void    init_sprites(t_game *game)
{
    //int   width; ??
    //int   height; ??

    //mlx_xpm_file_to_image -> prepara el archivo xpm para poder trabajar con él después
    game->floor_img = mlx_xpm_file_to_image(game->mlx, "filename", width, height); // en principio 32x32
    if (!game->floor_img)
    {
        //liberar lo necesario
        error_msg("Error: sprite not found");
    }
    // Deberíamos hacer lo mismo con todos
    game->wall_img;
    game->player_img;
    game->coin_img;
    game->exit_img;
}

/* void render_map(t_game *game)
{
    int x = 0;
    int y = 0;
    
    while (game->map[y])
    {
        x = 0;
        while (game->map[x][y])
        {
            if (game->map[x][y] == FLOOR)
                mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[x][y] == WALL)
                mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[x][y] == PLAYER)
                mlx_put_image_to_window(game->mlx, game->win, game->player_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[x][y] == COIN)
                mlx_put_image_to_window(game->mlx, game->win, game->coin_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[x][y] == EXIT)
                mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
} */
