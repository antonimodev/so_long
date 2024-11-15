/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:52:43 by antonimo          #+#    #+#             */
/*   Updated: 2024/11/15 13:57:55 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

/* void    destroy_images(t_game *game)
{
    mlx_destroy_image(game->mlx, game->floor_img.img);
    mlx_destroy_image(game->mlx, game->wall_img.img);
    mlx_destroy_image(game->mlx, game->player_img.img);
    mlx_destroy_image(game->mlx, game->coin_img.img);
    mlx_destroy_image(game->mlx, game->exit_img.img);
} */