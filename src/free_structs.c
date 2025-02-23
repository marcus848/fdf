/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:39:47 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/03 17:42:45 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
//
void	free_all(t_fdf *fdf)
{
	if (fdf->menu)
		free_menu(fdf);
	if (fdf->map)
		free_map(fdf->map);
	if (fdf->img && fdf->img->img)
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
}

void	free_menu(t_fdf *fdf)
{
	if (fdf->menu && fdf->menu->sidebar_img)
		mlx_destroy_image(fdf->mlx, fdf->menu->sidebar_img);
	if (fdf->menu)
		free(fdf->menu);
}

void	free_map(t_map *map)
{
	if (map->coordinates)
	{
		free_coordinates(map->coordinates, map->max_x);
		free(map->coordinates);
	}
	free(map);
}
