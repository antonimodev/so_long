/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:23:46 by antonimo          #+#    #+#             */
/*   Updated: 2024/06/12 11:10:17 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "lib/minilibx/mlx.h"
# include "lib/libft/libft.h"

#define TILE_SIZE 32

// Entities definition
# define FLOOR '0'
# define WALL '1'
# define PLAYER 'P'
# define COIN 'C'
# define EXIT 'E'
# define VISITED 'V' // Added VISITED definition

// Movements key ASCII
# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364

# define KEY_Q				113
# define KEY_ESC  			65307


// Entities struct (Player, Collectibles and Exit)
typedef struct s_entities
{
	int	player_counter;
	int	exit_counter;
	int	coin_counter; // Changed from collectible_counter to coin_counter
}	t_entities;

// Map coords (x, y)
typedef	struct s_coords
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
    void        *mlx;           	// Conexión con MiniLibX
    void        *win;           	// Ventana del juego
    t_image     floor_img;          // Imagen del suelo
    t_image     wall_img;       	// Imagen de la pared
    t_image     player_img;     	// Imagen del jugador
    t_image     coin_img;       	// Imagen de la moneda
    t_image     exit_img;       	// Imagen de la salida
    char        **map;          	// Mapa del juego
    char        **map_copy;        	// copia del mapa del juego
    int         map_width;      	// Ancho del mapa
    int         map_height;     	// Alto del mapa
    t_coords    player_pos;     	// Posición del jugador
    t_entities  entities;       	// Entidades del juego
    int         coins_collected;	// Monedas recogidas
} t_game;

// Map_validation.c
void		map_validation(t_game *game, char *map);
char		*txt_to_line(char *txt);
char		*process_txt(int fd);
void	    validate_extension(char *file);

// set_map.c
void	    set_map_dimension(t_game *game);
void        set_map(t_game *game, char *file);

// Validations.c
void		validate_edges(char **lines);
void		validate_body(char **lines, t_entities *entities);
void		validate_entities(t_entities *entities, char **lines);
bool		validate_walls(char *lines);
bool		validate_len(char *str, int len);

// Validations_utils.c
void		count_entities(char *line, t_entities *entities);
char		*gnl_cat(char *s1, char *s2);
void		reachable_entities(char **lines, t_entities entities, t_coords p_coords);
void		flood_fill(int x, int y, int *coins, char **map, bool *exit);
void		find_player(char **map, t_coords *player_cords);

// so_long_init.c
void        init_mlx(t_game *game);
void        init_sprites(t_game *game);

// sprite_utils.c
t_image     new_sprite(t_game *game, char *path, const char *entity);
void        destroy_images(t_game *game);

// handle_input.c
int         handle_input(int key, t_game *game);

// free.c
void        free_all(t_game *game);

// placeholder
void        render_map(t_game *game);
void        find_sprite(t_game *game, int y, int x);
void        render_sprite(t_game *game, t_image sprite, int line, int column);

#endif