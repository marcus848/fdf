/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:31:36 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/03 19:47:17 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	translate(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_UP)
		fdf->cam->offset_y -= 10;
	if (keycode == KEY_DOWN)
		fdf->cam->offset_y += 10;
	if (keycode == KEY_LEFT)
		fdf->cam->offset_x -= 10;
	if (keycode == KEY_RIGTH)
		fdf->cam->offset_x += 10;
}

void	scale_z(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_Z)
		fdf->cam->scale_z += 0.1;
	if (keycode == KEY_X)
		fdf->cam->scale_z -= 0.1;
}

void	zoom(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_PLUS)
		fdf->cam->scale_factor += 1;
	if (keycode == KEY_MINUS)
		fdf->cam->scale_factor -= 1;
}
