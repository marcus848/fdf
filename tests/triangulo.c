/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangulo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:41:49 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/09 11:05:49 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	size_line;
	int	endian;
}		t_data;

void	my_pixel_put(t_data *data, int x, int y, int color);

int	main(void)
{
	void	*mlx;
	void	*win_mlx;
	int	red = 0x00FF0000, white = 0x00FFFFFF;
	int	width = 1920, heigth = 360;
	t_data	img;
	int	x = 0, y = 0, z = 0, i = 0, j = 0;
	mlx = mlx_init();
	win_mlx = mlx_new_window(mlx, width, heigth, "Triangulo");
	img.img = mlx_new_image(mlx, width, heigth);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line, &img.endian);
	i = width / 2;
	j = heigth / 10;
	while (j < heigth / 10 * 9)
	{
		my_pixel_put(&img, i - x, j, red);
		my_pixel_put(&img, i + x, j, red);
		x++;
		j++;
	}
	z = i - x;
	while (z <= i + x)
	{
		my_pixel_put(&img, z, j, red);
		z++;
	}

	mlx_put_image_to_window(mlx, win_mlx, img.img, 0, 0);
	mlx_loop(mlx);
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

