/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:18:38 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/08 19:47:38 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	size_line;
	int	endian;
} 		t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int	width = 680, height = 360;
	int	red = 0xFF0000, white = 0xFFFFFF;
	int	i = -1, j = -1;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "Ola mundo");
	img.img = mlx_new_image(mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line, &img.endian);
	while (i++ <= height )
	{
		while ( j++ <= width / 4)
			my_mlx_pixel_put(&img, j, i, red);
		j = -1;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	int	space = height / 10;
	char	*str = "Ola Mundo";
	mlx_string_put(mlx, mlx_win, width / 4 - (ft_strlen(str) * 15), space, white, str);
	mlx_string_put(mlx, mlx_win, width / 4 - (ft_strlen(str) * 15), space*2, white, str);
	mlx_string_put(mlx, mlx_win, width / 4 - (ft_strlen(str) * 15), space*3, white, str);
	mlx_string_put(mlx, mlx_win, width / 4 - (ft_strlen(str) * 15), space*4, white, str);
	mlx_string_put(mlx, mlx_win, width / 4 - (ft_strlen(str) * 15), space*5, white, str);
	mlx_loop(mlx);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
