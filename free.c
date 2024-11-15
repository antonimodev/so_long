/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:54:04 by antonimo          #+#    #+#             */
/*   Updated: 2024/11/15 13:57:50 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    destroy_images(t_game *game)
{
    if (game->floor_img.img)
        mlx_destroy_image(game->mlx, game->floor_img.img);
    if (game->wall_img.img)
        mlx_destroy_image(game->mlx, game->wall_img.img);
    if (game->player_img.img)
        mlx_destroy_image(game->mlx, game->player_img.img);
    if (game->coin_img.img)
        mlx_destroy_image(game->mlx, game->coin_img.img);
    if (game->exit_img.img)
        mlx_destroy_image(game->mlx, game->exit_img.img);
}

void    free_all(t_game *game)
{
    destroy_images(game);
    free_matrix(game->map);
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
}