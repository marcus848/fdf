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

void	rotate_hook(int keycode, t_fdf *fdf)
{
	double	step;

	step = 2 * ANG_1;
	if (keycode == KEY_S)
		fdf->cam->alpha -= step;
	if (keycode == KEY_W)
		fdf->cam->alpha += step;
	if (keycode == KEY_A)
		fdf->cam->gamma -= step;
	if (keycode == KEY_D)
		fdf->cam->gamma += step;
	if (keycode == KEY_Q)
		fdf->cam->beta -= step;
	if (keycode == KEY_E)
		fdf->cam->beta += step;
}

void	change_projection(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_I)
		fdf->cam->type_project = ISOMETRIC;
	if (keycode == KEY_T)
		fdf->cam->type_project = TOP;
	if (keycode == KEY_P)
		fdf->cam->type_project = SIDE_PARALLEL;
	reset_angles(fdf->cam);
}

void	change_theme(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_L)
	{
		if (fdf->theme == BACKGROUND_DEFAULT)
			fdf->theme = LINE_DEFAULT;
		else
			fdf->theme = BACKGROUND_DEFAULT;
	}
}
