/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:57:21 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/03 20:11:04 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	make_menu(t_fdf *fdf)
{
	int	width;
	int	height;

	if (!fdf->menu)
		fdf->menu = init_menu();
	change_menu(fdf);
	fdf->menu->sidebar_img = mlx_xpm_file_to_image(fdf->mlx, fdf->menu->name,
			&width, &height);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->menu->sidebar_img, 0, 0);
}

void	change_menu(t_fdf *fdf)
{
	if (fdf->menu && fdf->menu->sidebar_img)
		mlx_destroy_image(fdf->mlx, fdf->menu->sidebar_img);
	if (fdf->theme == LINE_DEFAULT)
		fdf->menu->name = "./menu/ligth.xpm";
	else
		fdf->menu->name = "./menu/dark.xpm";
}
