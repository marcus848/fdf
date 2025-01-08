/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:08:29 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/08 19:46:57 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int	i = -1, j;
	int	heigth = 360;
	int	width = 680;
	int	color = 0xFF0000;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, heigth, "Hello World");
	while ( i++ <= heigth )
	{
		j = -1;
		while ( j++ <= width / 4)
			mlx_pixel_put(mlx, mlx_win, j, i, color);
	}
	int space = heigth / 10;

	mlx_string_put(mlx, mlx_win, width / 4 - (ft_strlen("Ola Mundo") * 15), space, 0xFFFFFF, "Ola Mundo");
	mlx_string_put(mlx, mlx_win, width / 4 - (ft_strlen("Ola Mundo") * 15), space *2, 0xFFFFFF, "Ola Mundo");
	mlx_string_put(mlx, mlx_win, width / 4 - (ft_strlen("Ola Mundo") * 15), space * 3, 0xFFFFFF, "Ola Mundo");
	mlx_string_put(mlx, mlx_win, width / 4 - (ft_strlen("Ola Mundo") * 15), space * 4, 0xFFFFFF, "Ola Mundo");
	mlx_string_put(mlx, mlx_win, width / 4 - (ft_strlen("Ola Mundo") * 15), space * 5, 0xFFFFFF, "Ola Mundo");
	mlx_loop(mlx);
}
