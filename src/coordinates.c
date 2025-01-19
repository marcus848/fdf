/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:02:09 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/18 19:37:19 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_map	*make_map(int fd)
{
	t_map	*map;
	char	*line;

	map = init_map();
	line = get_next_line(fd);
	while (line)
	{
		if (!process_line(map, line))
		{
			free(line);
			free_line_gnl(fd);
			free_map(map);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
		map->max_y++;
	}
	return (map);
}

int	process_line(t_map *map, char *line)
{
	char	**split;
	int		columns;

	split = ft_split(line, ' ');
	if (!split)
		return (0);
	columns = count_arrays((void **) split);
	if (map->max_y == 0)
		map->max_x = columns;
	else if (columns != map->max_x)
		return (free_tokens(split), 0);
	map->coordinates = get_points(split, map);
	if (!map->coordinates)
		return (free_tokens(split), 0);
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
