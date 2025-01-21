/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:10:56 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/21 18:09:19 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <unistd.h>

t_fdf	*init_fdf(char *file_name)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->map = make_map(file_name);
	if (!fdf->map)
	{
		free(fdf);
		error(1);
	}
	fdf->mlx = mlx_init();
	fdf->win_x = WIN_WIDTH;
	fdf->win_y = WIN_HEIGHT;
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_x, fdf->win_y, "fdf");
	fdf->line = NULL;
	fdf->scale = scale(fdf->map);
	return (fdf);
}

t_img	*init_img(void *mlx)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	img->buffer = mlx_get_data_addr(img->img, &img->bits_per_pixel,
				 &img->size_line, &img->endian);
	img->line = NULL;
	return (img);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->coordinates = NULL;
	map->max_x = 0;
	map->max_y = 0;
	map->max_z = 0;
	map->min_z = 0;
	return (map);
}

t_line	*init_line(t_point start, t_point end)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->p1.x = start.x;
	line->p1.y = start.y;
	line->p1.z = start.z;
	line->p1.color = start.color;
	line->p2.x = end.x;
	line->p2.y = end.y;
	line->p2.z = end.z;
	line->p2.color = end.color;
	isometric(line);
	line->dx = abs((int)(line->p2.x - line->p2.x));
	line->dx = abs((int)(line->p2.y - line->p2.y));
	if (line->p1.x < line->p2.x)
		line->sx = 1;
	else
		line->sx = -1;
	if (line->p1.y < line->p2.y)
		line->sy = 1;
	else
		line->sy = -1;
	return (line);
}
