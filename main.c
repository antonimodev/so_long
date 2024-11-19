/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:17:05 by antonimo          #+#    #+#             */
/*   Updated: 2024/11/19 13:48:26 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
    t_game game;
    
    map_validation(&game, "maps/map.ber");
    init_mlx(&game);
    init_sprites(&game);
    render_map(&game);
    mlx_hook(game.win, KeyPress, KeyPressMask, handle_input, &game);
	/* mlx_hook(game.win, DestroyNotify, \
	ButtonPressMask, close_game, &game); */
	mlx_hook(game.win, Expose, ExposureMask, render_map, &game);
    mlx_loop(game.mlx);
    printf("\n\n ----------------- GUCCI ----------------- \n\n");
    return (0);
}
