/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:17:05 by antonimo          #+#    #+#             */
/*   Updated: 2024/11/12 12:31:29 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
    t_game game;
    
    map_validation(&game, "maps/map.ber");
    init_mlx(&game);
    render_map(&game);
    
    printf("\n\n ----------------- GUCCI ----------------- \n\n");
    return (0);
}


/* int main(void)
{
    map_validation("maps/map.ber");
    printf("GUCCI\n");
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    int     img_width;
    int     img_height;

    mlx = mlx_init();
    if (!mlx)
        return(NULL);
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    img.img = mlx_xpm_file_to_image(mlx, "images/mario.xpm", &img_width, &img_height);
    if (!img.img)
    {
        printf("Error al cargar la imagen\n");
        return (1);
    }
    // Poner la imagen en la ventana
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
    return (0);
} */
