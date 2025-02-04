/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:14:58 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/23 18:58:30 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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

void	drawline(t_point point1, t_point point2, t_fdf *fdf)
{
	t_delta	d;
	float	fraction;

	d.pixels = getpixels(point1, point2);
	d.deltax = (point2.x - point1.x) / d.pixels;
	d.deltay = (point2.y - point1.y) / d.pixels;
	d.x = point1.x;
	d.y = point1.y;
	while (d.pixels)
	{
		if (fdf->theme == LINE_DEFAULT)
		{
			// if (point1.color == LINE_DEFAULT)
			// 	point1.color = BACKGROUND_DEFAULT;
			// else
			// 	point1.color = change_color(point1);
			// if (point2.color == LINE_DEFAULT)
			// 	point2.color = BACKGROUND_DEFAULT;
			// else
			// 	point2.color = change_color(point2);
			point1.color = change_color(point1);
			point2.color = change_color(point2);
		}
		fraction = calculate_fraction(d.x, d.y, &point1, &point2);
		d.c = interpolate_colors(point1.color, point2.color, fraction);
		if (d.x >= 0 && d.x < WIN_WIDTH && d.y >= 0 && d.y < WIN_HEIGHT)
			my_mlx_pixel_put(fdf->img, d.x, d.y, d.c);
		d.x += d.deltax;
		d.y += d.deltay;
		d.pixels--;
	}
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
