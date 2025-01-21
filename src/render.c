/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:16:28 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/21 20:19:28 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fdf.h"

void bresenham1(t_point p1, t_point p2, void *mlx, void *win);
void	ft_drawline(t_point point1, t_point point2, void *mlx, void *win);
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
void scale_coordinates(t_fdf *fdf)
{
    int x, y;

    for (y = 0; y < fdf->map->max_y; y++)
    {
        for (x = 0; x < fdf->map->max_x; x++)
        {
            // Multiplicando as coordenadas por 100
            fdf->map->coordinates[x][y].x *= scale(fdf->map);
            fdf->map->coordinates[x][y].y *= scale(fdf->map);
            fdf->map->coordinates[x][y].z *= scale(fdf->map);
        }
    }
}


void offset(t_fdf *fdf)
{
    int x, y;

    for (y = 0; y < fdf->map->max_y; y++)
    {
        for (x = 0; x < fdf->map->max_x; x++)
        {
            // Multiplicando as coordenadas por 100
            fdf->map->coordinates[x][y].x += WIN_WIDTH / 1.75;
            fdf->map->coordinates[x][y].y += WIN_HEIGHT / 2;
        }
    }
}

void render(t_fdf *fdf)
{
    int x, y;
	
	scale_coordinates(fdf);
	isometric(fdf);
	offset(fdf);
    y = 0;
    while (y < fdf->map->max_y)
    {
        x = 0;
        while (x < fdf->map->max_x)
        {
            // Linha horizontal (x -> x+1)
            if (x < fdf->map->max_x - 1)
            {
                // bresenham1(fdf->map->coordinates[x][y], fdf->map->coordinates[x + 1][y], fdf->mlx, fdf->win);
                ft_drawline(fdf->map->coordinates[x][y], fdf->map->coordinates[x + 1][y], fdf->mlx, fdf->win);
            }

            // Linha vertical (y -> y+1)
            if (y < fdf->map->max_y - 1)
            {
                ft_drawline(fdf->map->coordinates[x][y], fdf->map->coordinates[x][y + 1], fdf->mlx, fdf->win);
            }

            x++;
        }
        y++;
    }
}


void bresenham1(t_point p1, t_point p2, void *mlx, void *win)
{
    int x, y;
    int dx, dy;
    int d, sx, sy;
	int color = p1.color;
    x = (int)p1.x;
    y = (int)p1.y;
    dx = abs((int)p2.x - (int)p1.x);
    dy = abs((int)p2.y - (int)p1.y);
    sx = (p2.x > p1.x) ? 1 : -1; // Direção do incremento de x
    sy = (p2.y > p1.y) ? 1 : -1;
    d = 2 * dy - dx;
    mlx_pixel_put(mlx, win, x, y, color);

    if (dx > dy)
    {
        while (x != (int)p2.x)
        {
            mlx_pixel_put(mlx, win, x, y, color);
            if (d >= 0)
            {
                y += sy;
                d -= 2 * dx;
            }
            d += 2 * dy;
            x += sx;
        }
    }
    else
    {
        while (y != (int)p2.y)
        {
            mlx_pixel_put(mlx, win, x, y, color);
            if (d >= 0)
            {
                x += sx;
                d -= 2 * dy;
            }
            d += 2 * dx;
            y += sy;
        }
    }
    mlx_pixel_put(mlx, win, x, y, color);
}


void	render_line(t_fdf *fdf, t_point start, t_point end)
{
	fdf->line = init_line(start, end);
	bresenham(fdf, fdf->line);
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
void	ft_drawline(t_point point1, t_point point2, void *mlx, void *win)
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
