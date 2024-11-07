/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:21:46 by antonimo          #+#    #+#             */
/*   Updated: 2024/11/07 12:00:03 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_validation(char *map)
{
	char		*super_line;
	char		**lines;
	t_coords	player_coords;

	/* if (!map)
		error_msg("There is no map!"); */
	super_line = txt_to_line(map);
	lines = ft_split(super_line, '\n');
	free(super_line);
	validate_edges(lines);
	validate_body(lines);
	player_coords = find_player(lines); // Podriamos recogerlo en una variable quitnado player_coords
	//funcion flood_fill(player_coords);
	// printf("%d\n%d\n", player_coords.x, player_coords.y);
	free_matrix(lines);
}

char	*txt_to_line(char *txt)
{
	int		fd;
	char	*super_line;

	fd = open(txt, O_RDONLY);
	if (fd == -1)
		return (NULL);
	super_line = process_txt(fd);
	close(fd);
	return (super_line);
}

char	*process_txt(int fd)
{
	char	*super_line;
	char	*gnl_line;

	super_line = ft_strdup("");
	gnl_line = get_next_line(fd);
	if (!gnl_line)
	{
		free(super_line);
		error_msg("Error: converting text to line");
	}
	while (gnl_line)
	{
		super_line = gnl_cat(super_line, gnl_line);
		free(gnl_line);
		gnl_line = get_next_line(fd);
	}
	return (super_line);
}

/************* PARA LIBFT *************/

// Función que comprueba que todos los chr sean iguales


char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = malloc((ft_strlen_gnl(s1) + 1) * sizeof(char));
	if (ptr == NULL)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}



void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
