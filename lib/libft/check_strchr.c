/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_strchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:43:43 by antonimo          #+#    #+#             */
/*   Updated: 2024/10/28 11:00:43 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_strchr(char *str, char chr)
{
	if (!chr)
		return (0);
	while (str)
	{
		if (*str == chr)
			return (1);
		str++;
	}
	return (0);
}
