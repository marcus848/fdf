/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:10:56 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/18 19:32:47 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <fcntl.h>
#include <stdlib.h>

t_fdf	*init_fdf(char *file_name)
{
	t_fdf	*fdf;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error(1);
	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->map = make_map(fd);
	if (!fdf->map)
	{
		close(fd);
		free(fdf);
		error(1);
	}
	print_points(fdf->map->coordinates, fdf->map->max_x * fdf->map->max_y);
	free_map(fdf->map);
	return (fdf);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->coordinates = NULL;
	map->max_x = 0;
	map->max_y = 0;
	return (map);
}
