/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:02:09 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/16 16:51:38 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_map	*make_map(int fd)
{
	t_map	*map;
	char	*line;
	int		y;

	map = init_map();
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!process_line(map, line, y))
		{
			free(line);
			free_map(map);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
		y++;
	}
	map->max_y = y;
	return (map);
}

int	process_line(t_map *map, char *line, int y)
{
	char **split;
	t_point **points;
	int		columns;

	split = ft_split(line, ' ');
	if (!split)
		return (0);
	columns = count_arrays((void **) split);
	if (y == 0)
		map->max_x = columns;
	else if (columns != map->max_x)
	{
		free_tokens(split);
		return (0);
	}
	points = get_points(split, columns , y + 1);
	if (!points)
	{
		free_tokens(split);
		return (0);
	}
	// print_points(points, columns);
	free_points(points, columns);
	free_tokens(split);
	return (1);
}

int	count_arrays(void **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		i++;
	}
	return (i);
}
