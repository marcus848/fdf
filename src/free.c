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
	if (map->coordinates)
		free(map->coordinates);
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

void	free_points(t_point **points, int size)
{
	int	i;

	i = 0;
	if (points)
	{
		while (i < size)
		{
			free(points[i]);
			i++;
		}
		free(points);
	}
}

// free static line in GNL;
void	free_line_gnl(int fd)
{
	while (get_next_line(fd))
		;
}
