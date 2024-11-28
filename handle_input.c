/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:23:55 by antonimo          #+#    #+#             */
/*   Updated: 2024/11/28 13:54:15 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_movements(t_game *game)
{
	game->move_counter++;
	printf("Movements: %d.\n", game->move_counter);
}

void	update_map(t_game *game, t_coords new, t_coords last)
{
	if (game->map_copy[new.x][new.y] == EXIT)
	{
		game->map_copy[new.x][new.y] = ON_EXIT;
		game->map_copy[last.x][last.y] = FLOOR;
	}
	else if (game->map_copy[last.x][last.y] == ON_EXIT)
	{
		game->map_copy[new.x][new.y] = PLAYER;
		game->map_copy[last.x][last.y] = EXIT;
	}
	else
	{
		game->map_copy[new.x][new.y] = PLAYER;
		game->map_copy[last.x][last.y] = FLOOR;
	}
}

void	move_player(t_game *game, int new_x, int new_y)
{
	t_coords	new;
	t_coords	last;

	new.x = new_x;
	new.y = new_y;
	last.x = game->player_pos.x;
	last.y = game->player_pos.y;
	if (game->map_copy[new.x][new.y] == WALL)
		return ;
	if (game->map_copy[new.x][new.y] == EXIT
	&& game->entities.coin_counter == 0)
		victory(game);
	if (game->map_copy[new.x][new.y] == COIN)
		game->entities.coin_counter--;
	game->player_pos.x = new.x;
	game->player_pos.y = new.y;
	update_map(game, new, last);
	print_movements(game);
	render_map(game);
}

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
