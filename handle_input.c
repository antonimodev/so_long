/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:23:55 by antonimo          #+#    #+#             */
/*   Updated: 2024/11/25 13:19:37 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int key, t_game *game)
{
	if (key == KEY_W || key == KEY_UP)
		move_player(game, game->player_pos.x - 1, game->player_pos.y);
	if (key == KEY_A || key == KEY_LEFT)
		move_player(game, game->player_pos.x, game->player_pos.y - 1);
	if (key == KEY_S || key == KEY_DOWN)
		move_player(game, game->player_pos.x + 1, game->player_pos.y);
	if (key == KEY_D || key == KEY_RIGHT)
		move_player(game, game->player_pos.x, game->player_pos.y + 1);
	if (key == KEY_Q || key == KEY_ESC)
		close_game(game);
	return (0);
}

void	move_player(t_game *game, int new_x, int new_y)
{
	int	last_x;
	int	last_y;

	last_x = game->player_pos.x;
	last_y = game->player_pos.y;
	if (game->map_copy[new_x][new_y] == WALL
	|| (game->map_copy[new_x][new_y] == EXIT && game->entities.coin_counter))
		return ;
	if (game->map_copy[new_x][new_y] == EXIT
	&& game->entities.coin_counter == 0)
		victory(game);
	if (game->map_copy[new_x][new_y] == COIN)
		game->entities.coin_counter--;
	game->player_pos.x = new_x;
	game->player_pos.y = new_y;
	game->map_copy[new_x][new_y] = PLAYER;
	game->map_copy[last_x][last_y] = FLOOR;
	print_movements(game);
	render_map(game);
}

void	victory(t_game *game)
{
	print_movements(game);
	printf("\n");
	printf("███████████████████████████████████████████████████████████████\n");
	printf("█▌                                                           ▐█\n");
	printf("█▌  ██╗   ██╗██╗ ██████╗████████╗ ██████╗ ██████╗ ██╗   ██╗  ▐█\n");
	printf("█▌  ██║   ██║██║██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗╚██╗ ██╔╝  ▐█\n");
	printf("█▌  ██║   ██║██║██║        ██║   ██║   ██║██████╔╝ ╚████╔╝   ▐█\n");
	printf("█▌  ╚██╗ ██╔╝██║██║        ██║   ██║   ██║██╔══██╗  ╚██╔╝    ▐█\n");
	printf("█▌   ╚████╔╝ ██║╚██████╗   ██║   ╚██████╔╝██║  ██║   ██║     ▐█\n");
	printf("█▌    ╚═══╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝   ╚═╝     ▐█\n");
	printf("█▌                                                           ▐█\n");
	printf("█▌  ██████╗  ██████╗ ██╗   ██╗ █████╗ ██╗     ███████╗██╗    ▐█\n");
	printf("█▌  ██╔══██╗██╔═══██╗╚██╗ ██╔╝██╔══██╗██║     ██╔════╝██║    ▐█\n");
	printf("█▌  ██████╔╝██║   ██║ ╚████╔╝ ███████║██║     █████╗  ██║    ▐█\n");
	printf("█▌  ██╔══██╗██║   ██║  ╚██╔╝  ██╔══██║██║     ██╔══╝  ╚═╝    ▐█\n");
	printf("█▌  ██║  ██║╚██████╔╝   ██║   ██║  ██║███████╗███████╗██╗    ▐█\n");
	printf("█▌  ╚═╝  ╚═╝ ╚═════╝    ╚═╝   ╚═╝  ╚═╝╚══════╝╚══════╝╚═╝    ▐█\n");
	printf("█▌                                                           ▐█\n");
	printf("███████████████████████████████████████████████████████████████\n");
	printf("\n");
	free_all(game);
	exit(EXIT_SUCCESS);
}

int	close_game(t_game *game)
{
	print_movements(game);
	printf("\n");
	printf("█████████████████████████████████████████████████████████\n");
	printf("█▌                                                     ▐█\n");
	printf("█▌  ██████╗ ███████╗███████╗███████╗ █████╗ ████████╗  ▐█\n");
	printf("█▌  ██╔══██╗██╔════╝██╔════╝██╔════╝██╔══██╗╚══██╔══╝  ▐█\n");
	printf("█▌  ██║  ██║█████╗  █████╗  █████╗  ███████║   ██║     ▐█\n");
	printf("█▌  ██║  ██║██╔══╝  ██╔══╝  ██╔══╝  ██╔══██║   ██║     ▐█\n");
	printf("█▌  ██████╔╝███████╗██║     ███████╗██║  ██║   ██║     ▐█\n");
	printf("█▌  ╚═════╝ ╚══════╝╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝     ▐█\n");
	printf("█▌                                                     ▐█\n");
	printf("█████████████████████████████████████████████████████████\n");
	printf("\n");
	free_all(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	print_movements(t_game *game)
{
	game->move_counter++;
	printf("Movements: %d.\n", game->move_counter);
}
