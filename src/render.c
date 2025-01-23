/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:16:28 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/23 18:58:06 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	render(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	// clear_image(fdf->img, MAX_PIXELS * 4);
	ft_memset(fdf->img->addr, BACKGROUND_DEFAULT, MAX_PIXELS * 4);
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{
			if (x < fdf->map->max_x - 1)
			{
				render_line(fdf, fdf->map->coordinates[x][y],
					fdf->map->coordinates[x + 1][y]);
			}
			if (y < fdf->map->max_y - 1)
			{
				render_line(fdf, fdf->map->coordinates[x][y],
					fdf->map->coordinates[x][y + 1]);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
}

void	render_line(t_fdf *fdf, t_point start, t_point end)
{
	start.z *= fdf->cam->scale_z;
	end.z *= fdf->cam->scale_z;
	fdf->img->line = init_line(start, end, fdf);
	isometric(fdf->img->line);
	scale(fdf->img->line, fdf->cam->scale_factor);
	offset(fdf->img->line, fdf->cam);
	drawline(fdf->img->line->start, fdf->img->line->end, fdf);
	free(fdf->img->line);
}

