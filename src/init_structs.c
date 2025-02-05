/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:10:56 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/03 19:54:21 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdlib.h>
#include <unistd.h>

t_fdf	*init_fdf(char *file_name)
{
	t_fdf	*fdf;

	fdf = start_fdf();
	if (!fdf)
		return (NULL);
	fdf->map = make_map(file_name, fdf);
	fdf->mlx = mlx_init();
	fdf->win_x = WIN_WIDTH + 200;
	fdf->win_y = WIN_HEIGHT;
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_x, fdf->win_y, "fdf");
	fdf->img = init_img(fdf->mlx);
	if (!fdf->img)
		error(6, fdf);
	fdf->cam = init_cam(fdf);
	if (!fdf->cam)
		error(7, fdf);
	return (fdf);
}

t_img	*init_img(void *mlx)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	img->line = NULL;
	return (img);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->coordinates = NULL;
	map->max_x = 0;
	map->max_y = 0;
	map->max_z = 0;
	map->min_z = 0;
	map->have_color = 0;
	return (map);
}

t_line	*init_line(t_point start, t_point end, t_fdf *fdf)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->start.x = start.x;
	line->start.y = start.y;
	line->start.z = start.z;
	line->start.color = start.color;
	line->end.x = end.x;
	line->end.y = end.y;
	line->end.z = end.z;
	line->end.color = end.color;
	line->transform_z = max((fdf->map->max_z - fdf->map->min_z),
			max(fdf->map->max_x, fdf->map->max_y));
	return (line);
}

t_cam	*init_cam(t_fdf *fdf)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		return (NULL);
	cam->offset_x = WIN_WIDTH / 2;
	cam->offset_y = WIN_HEIGHT / 2;
	cam->scale_z = 1;
	cam->scale_factor = scale_points(fdf->map);
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	cam->type_project = ISOMETRIC;
	return (cam);
}
