/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:02:09 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/22 20:17:19 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <fcntl.h>

t_map	*make_map(char *file_name, t_fdf *fdf)
{
	t_map	*map;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error(1, fdf);
	close(fd);
	map = init_map();
	if (!map)
		error(2, fdf);
	get_dimensions(file_name, map, fdf);
	map->coordinates = init_coordinates(map->max_y, map->max_x);
	if (!map->coordinates)
		error(5, fdf);
	get_points(file_name, map);
	center_to_origin(map);
	return (map);
}
