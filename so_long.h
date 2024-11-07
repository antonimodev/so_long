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
# include "lib/libft/libft.h"

// Entities definition
# define WALL '1'
# define PLAYER 'P'
# define COIN 'C'
# define EXIT 'E'

// Entities struct (Player, Collectibles and Exit)
typedef struct s_entities
{
	int	player_counter;
	int	exit_counter;
	int	collectible_counter;
}	t_entities;

// Map coords (x, y)
typedef	struct s_coords
{
	int	x;
	int	y;
}	t_coords;

// Map_validation.c
void		map_validation(char *map);
char		*txt_to_line(char *txt);
char		*process_txt(int fd);

// Validations.c
void		validate_edges(char **lines);
void		validate_body(char **lines);
void		validate_entities(t_entities entities, char **lines);
bool		validate_walls(char *lines);
bool		validate_len(char *str, int len);

// Validations_utils.c
void		count_entities(char *line, t_entities *entities);
char		*gnl_cat(char *s1, char *s2);
t_coords	find_player(char **map);

#endif