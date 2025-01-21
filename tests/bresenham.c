/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:39:33 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/21 18:49:18 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	bresenham1(int p1[3], int p2[3], void *mlx, void *win, int color);
void	render_test(int ps[3][3][3], void *mlx, void *win, int color);
void	project_iso(int input[3], int output[3], int offset_x, int offset_y);
int main(void)
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 800, 600, "Bresenham Test");

	int ps[3][3][3] = {
		{
			{100, 100, 0},{200, 100, 0},{300, 100, 0}
		},
		{
			{100, 200, 0},{200, 200, -200},{300, 200, 0}
		},
		{
			{100, 300, 0},{200, 300, 0},{300, 300, 0}
		}
	};

	render_test(ps, mlx, win, 0x00FF0000);
	mlx_loop(mlx);
	return (0);
}

void	render_test(int ps[3][3][3], void *mlx, void *win, int color)
{
	int	x, y;
	int	proj1[3], proj2[3];

	// Centro da janela (ajuste para centralizar a renderização)
	int offset_x = 400; // Centro da largura (800 / 2)
	int offset_y = 300; // Centro da altura (600 / 2)

	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			if (x < 2) // Desenhar linha horizontal
			{
				project_iso(ps[y][x], proj1, offset_x, offset_y);
				project_iso(ps[y][x + 1], proj2, offset_x, offset_y);
				bresenham1(proj1, proj2, mlx, win, color);
			}
			if (y < 2) // Desenhar linha vertical
			{
				project_iso(ps[y][x], proj1, offset_x, offset_y);
				project_iso(ps[y + 1][x], proj2, offset_x, offset_y);
				bresenham1(proj1, proj2, mlx, win, color);
			}
			x++;
		}
		y++;
	}
}

void	project_iso(int input[3], int output[3], int offset_x, int offset_y)
{
	double	angle = M_PI / 6; // 30 graus
	double	cos_angle = cos(angle);
	double	sin_angle = sin(angle);

	// Projeção isométrica com deslocamento
	output[0] = (input[0] - input[1]) * cos_angle + offset_x;
	output[1] = (input[0] + input[1]) * sin_angle - input[2] + offset_y;
	output[2] = 0; // Z não é necessário para renderizar
}

void	bresenham1(int p1[3], int p2[3], void *mlx, void *win, int color)
{
	int	x, y;
	int	dx, dy;
	int	d, sx, sy;

	x = p1[0];
	y = p1[1];
	dx = abs(p2[0] - p1[0]);
	dy = abs(p2[1] - p1[1]);
	sx = (p2[0] > p1[0]) ? 1 : -1; // Direção do incremento de x
	sy = (p2[1] > p1[1]) ? 1 : -1;
	d = 2 * dy - dx;
	mlx_pixel_put(mlx, win, x, y, color);
	if (dx > dy)
	{
		d = 2 * dy - dx;
		while (x != p2[0])
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
		d = 2 * dx - dy;
		while (y != p2[1])
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
