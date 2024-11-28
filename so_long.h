/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:54:35 by antonimo          #+#    #+#             */
/*   Updated: 2024/11/28 13:55:49 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "lib/minilibx/mlx.h"
# include "/usr/include/X11/X.h"
# include "lib/libft/libft.h"

# define TILE_SIZE 70

// Entities definition
# define FLOOR				'0'
# define WALL				'1'
# define PLAYER				'P'
# define COIN				'C'
# define EXIT				'E'
# define ON_EXIT			'X'
# define VISITED			'V'

// Movements key ASCII
# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364

// Exit key ASCII
# define KEY_Q				113
# define KEY_ESC  			65307

typedef struct s_entities
{
	int	player_counter;
	int	exit_counter;
	int	coin_counter;
}	t_entities;

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_image
{
	void	*img;
	int		x;
	int		y;
}	t_image;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_image		on_exit_img;
	t_image		floor_img;
	t_image		wall_img;
	t_image		player_img;
	t_image		coin_img;
	t_image		exit_img;
	char		**map;
	char		**map_copy;
	int			map_width;
	int			map_height;
	int			move_counter;
	t_coords	player_pos;
	t_entities	entities;
}	t_game;

// map_validation.c
void		map_validation(t_game *game, char *map);
void		validate_extension(char *file);
char		*txt_to_line(char *txt);
char		*process_txt(int fd);
bool		check_line(char *line);

// set_map.c
void		set_map_dimension(t_game *game);
void		set_move_counter(t_game *game);
void		set_map(t_game *game, char *file);

// validations.c
void		validate_entities(t_entities *entities, t_game game);
void		validate_edges(t_game game);
void		validate_body(t_game game, t_entities *entities);
bool		validate_walls(char *lines);
bool		validate_len(char *str, int len);

// validations_utils.c
void		count_entities(char *line, t_entities *entities);
void		find_player(char **map, t_coords *player_cords);
void		flood_fill(int x, int y, t_entities *entities, char **map);
void		reachable_entities(t_game game, t_entities entities, \
			t_coords p_coords);
char		*gnl_cat(char *s1, char *s2);

// so_long_init.c
void		init_mlx(t_game *game);
void		hooks_mlx(t_game *game);
int			render_map(t_game *game);

// sprite_utils.c
void		init_sprite(t_game *game);
void		find_sprite(t_game *game, int y, int x);
void		render_sprite(t_game *game, t_image sprite, int line, int column);
t_image		new_sprite(t_game *game, char *path, const char *entity);

// handle_input.c
void		print_movements(t_game *game);
void		update_map(t_game *game, t_coords new, t_coords last);
void		move_player(t_game *game, int new_x, int new_y);
int			handle_input(int key, t_game *game);

// free.c
void		destroy_images(t_game *game);
void		free_all(t_game *game);

// finish.c
void		victory(t_game *game);
int			close_game(t_game *game);

#endif