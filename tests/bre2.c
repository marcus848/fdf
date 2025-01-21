/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bre2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:39:33 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/21 19:04:15 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
typedef struct s_point2
{
    double x;
    double y;
    int color;
} t_point2;
typedef struct s_delta
{
	double	deltax;
	double	deltay;
	double	deltacolor;
	double	x;
	double	y;
	double	c;
	int		pixels;
}	t_delta;

int	getpixels(t_point2 point1, t_point2 point2);
void	ft_drawline(t_point2 point1, t_point2 point2, void *mlx, void *win);

int main(void)
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 800, 600, "Bresenham Test");

	t_point2 ps[3][3] = {
		{
			{100, 100, 200},{200, 100, 100},{300, 100, 100}
		},
		{
			{100, 200, 100},{200, 200, 200},{300, 200, 100}
		},
		{
			{100, 300, 100},{200, 300, 100},{300, 300, 100}
		}
	};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
		    if (j < 2)
			ft_drawline(ps[i][j], ps[i][j + 1], mlx, win); // Linha horizontal
		    if (i < 2)
			ft_drawline(ps[i][j], ps[i + 1][j], mlx, win); // Linha vertical
		}
	}

    mlx_loop(mlx);
	mlx_loop(mlx);
	return (0);
}

int	getpixels(t_point2 point1, t_point2 point2)
{
	double	deltax;
	double	deltay;
	int		pixels;

	deltax = point2.x - point1.x;
	deltay = point2.y - point1.y;
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	return (pixels);
}

void ft_drawline(t_point2 point1, t_point2 point2, void *mlx, void *win)
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
		mlx_pixel_put(mlx, win, d.x, d.y, d.c);
		d.x += d.deltax;
		d.y += d.deltay;
		d.c += d.deltacolor;
		d.pixels--;
	}
}
