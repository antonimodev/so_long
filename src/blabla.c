/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blabla.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:38:42 by antonimo          #+#    #+#             */
/*   Updated: 2024/10/30 14:42:24 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_validation(char *map)
{
	int			fd;
	int			len;
	t_list		*gnl_lst;

	fd = open(map, O_RDONLY);
	gnl_lst = gnl_to_lst(fd);
	validate_map_edges(gnl_lst);
	validate_map_body(gnl_lst);
	ft_lstclear(gnl_lst, free);
}

t_list	*gnl_to_lst(int fd)
{
	char	*line;
	t_list	*gnl_lst;

	line = get_next_line(fd);
	if (!line)
		exit(EXIT_FAILURE);
	gnl_lst = ft_lstnew(line);
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			ft_lstadd_back(&gnl_lst, ft_lstnew(line));
	}
	return (gnl_lst);
}

void	validate_map_edges(t_list *gnl_lst)
{
	if (!all_chars_same(gnl_lst->content)
		|| !all_chars_same(ft_lstlast(gnl_lst)->content))
	{
		ft_lstclear(&gnl_lst, free);
		exit(EXIT_FAILURE);
	}
}

void	validate_map_body(t_list *gnl_lst)
{
	int			len;
	t_entities	entities;

	entities.player_counter = 0;
	entities.exit_counter = 0;
	entities.collectible_counter = 0;
	len = ft_strlen(gnl_lst->content);
	while (gnl_lst->next)
	{
		validate_map_len(gnl_lst, len);
		validate_map_sides(gnl_lst, '1');
		count_entities(gnl_lst->content, &entities);
		gnl_lst = gnl_lst->next;
	}
	validate_entities(gnl_lst, entities);
}

void	validate_map_len(t_list *gnl_lst, int len)
{
	if (!check_len(gnl_lst->content, len))
	{
		ft_lstclear(gnl_lst, free);
		exit(EXIT_FAILURE);
	}
}

bool	check_len(char *str, int len)
{
	if (ft_strlen(str) != len)
		return (false);
	return (true);
}

void validate_map_sides(t_list *gnl_lst, char c)
{
    int len;

    len = ft_strlen(gnl_lst->content);
    if (gnl_lst->content[0] != c || gnl_lst->content[--len] != c)
    {
        ft_lstclear(&gnl_lst, free);
        exit(EXIT_FAILURE);
    }
}

void	count_entities(char *line, t_entities *entities)
{
	entities->player_counter += count_char_in_str(line, 'P');
	entities->exit_counter += count_char_in_str(line, 'E');
	entities->collectible_counter += count_char_in_str(line, 'C');
}

void	validate_entities(t_list *gnl_lst, t_entities entities)
{
	if (entities.player_counter != 1 || entities.exit_counter != 1
		|| entities.collectible_counter < 1)
	{
		ft_lstclear(gnl_lst, free);
		exit(EXIT_FAILURE);
	}
}
