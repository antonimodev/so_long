/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:17:05 by antonimo          #+#    #+#             */
/*   Updated: 2024/12/02 14:10:20 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		ft_bzero(&game, sizeof(t_game));
		map_validation(&game, av[1]);
		init_mlx(&game);
		init_sprite(&game);
		render_map(&game);
		hooks_mlx(&game);
		mlx_loop(game.mlx);
	}
	else
		error_msg("Enter valid argument");
	return (0);
}
