/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:39:47 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/22 21:19:38 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
//
void	free_all(t_fdf *fdf)
{
	if (fdf->map)
		free_map(fdf->map);
	if (fdf->img->img)
		mlx_destroy_image(fdf->mlx, fdf->img->img);
	if (fdf->img)
		free(fdf->img);
	if (fdf->cam)
		free(fdf->cam);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->win)
		mlx_destroy_display(fdf->mlx);
	if (fdf->mlx)
		free(fdf->mlx);
	free(fdf);
	exit (0);
}

t_cam	*free_cam(t_cam *cam)
{
	free(cam);
	return (NULL);
}

t_img	*free_img(t_img *img, void *mlx_ptr, void *img_ptr)
{
	mlx_destroy_image(mlx_ptr, img_ptr);
	if (img->line)
		free(img->line);
	return (NULL);
}

void	free_map(t_map *map)
{
	if (map->coordinates)
	{
		free_coordinates(map->coordinates, map->max_x);
		free(map->coordinates);
	}
	free(map);
	// return (NULL);
}
