/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:05:27 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/22 20:13:57 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	get_points(char *file_name, t_map *map)
{
	char	*line;
	char	**split;
	int		fd;
	int		coord[2];

	fd = open(file_name, O_RDONLY);
	coord[0] = 0;
	while (coord[0] < map->max_y)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		coord[1] = 0;
		while (coord[1] < map->max_x)
		{
			fill_point(split[coord[1]], &map->coordinates[coord[1]][coord[0]],
				map, coord);
			free(split[coord[1]]);
			coord[1]++;
		}
		free(split);
		free(line);
		coord[0]++;
	}
	close(fd);
}

void	fill_point(char *point, t_point *coordinate, t_map *map, int coord[2])
{
	char	**info;
	int		i;

	coordinate->x = (float) coord[1];
	coordinate->y = (float) coord[0];
	coordinate->color = -1;
	if (ft_strchr(point, ','))
	{
		info = ft_split(point, ',');
		coordinate->z = (float) ft_atoi(info[0]);
		coordinate->color = (float) ft_atoi_base(info[1], 16);
		i = 0;
		while (info[i])
			free(info[i++]);
		free(info);
	}
	else
		coordinate->z = (float) ft_atoi(point);
	if (coordinate->z > map->max_z)
		map->max_z = coordinate->z;
	if (coordinate->z < map->min_z)
		map->min_z = coordinate->z;
}

void	center_to_origin(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->max_y)
	{
		x = 0;
		while (x < map->max_x)
		{
			map->coordinates[x][y].x -= (float)map->max_x / 2;
			map->coordinates[x][y].y -= (float)map->max_y / 2;
			x++;
		}
		y++;
	}
}

int	scale_points(t_map *map)
{
	float	scale_x;
	float	scale_y;
	float	scale_factor;

	scale_x = WIN_WIDTH / map->max_x;
	scale_y = WIN_HEIGHT / map->max_y;
	scale_factor = min(scale_x, scale_y);
	if (scale_factor < 4)
		return (2);
	return (scale_factor / 2);
}
