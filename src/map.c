/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:02:09 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/21 15:30:01 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <fcntl.h>

t_map	*make_map(char *file_name)
{
	t_map	*map;
	int		fd;
	
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error(3);
	close(fd);
	map = init_map();
	if (!map)
		return (NULL);
	get_dimensions(file_name, map);
	map->coordinates = init_coordinates(map->max_y, map->max_x);
	if (!map->coordinates)
	{
		free(map);
		return (NULL);
	}
	get_points(file_name, map);
	center_to_origin(map);
	return (map);
}


