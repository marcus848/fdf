/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:39:47 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/16 16:51:19 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->coordinates)
	{
		while (i < map->max_x * map->max_y)
		{
			free(map->coordinates[i]);
			i++;
		}
		free(map->coordinates);
	}
	free(map);
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

// free static line in GNL;
void	free_line_gnl(int fd)
{
	while (get_next_line(fd))
		;
}
