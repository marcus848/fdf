/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:16:28 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/22 20:44:36 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	render(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
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
	ft_drawline(fdf->img->line->start, fdf->img->line->end, fdf);
	free(fdf->img->line);
}

int	getpixels(t_point point1, t_point point2)
{
	double	deltax;
	double	deltay;
	int		pixels;

	deltax = point2.x - point1.x;
	deltay = point2.y - point1.y;
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	return (pixels);
}

void	ft_drawline(t_point point1, t_point point2, t_fdf *fdf)
{
	t_delta	d;

	d.deltax = point2.x - point1.x;
	d.deltay = point2.y - point1.y;
	d.pixels = getpixels(point1, point2);
	d.deltax /= d.pixels;
	d.deltay /= d.pixels;
	d.x = point1.x;
	d.y = point1.y;
	d.c = point1.color;
	d.deltacolor = point2.color - point1.color;
	d.deltacolor /= d.pixels;
	while (d.pixels)
	{
		if (d.x >= 0 && d.x < WIN_WIDTH && d.y >= 0 && d.y < WIN_HEIGHT)
			my_mlx_pixel_put(fdf->img, d.x, d.y, d.c);
		d.x += d.deltax;
		d.y += d.deltay;
		d.c += d.deltacolor;
		d.pixels--;
	}
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
