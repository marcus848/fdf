/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:31:36 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/23 19:09:23 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	translate(int keycode, t_fdf *fdf)
{
	if (keycode == 65362)
		fdf->cam->offset_y -= 10;
	if (keycode == 65364)
		fdf->cam->offset_y += 10;
	if (keycode == 65361)
		fdf->cam->offset_x -= 10;
	if (keycode == 65363)
		fdf->cam->offset_x += 10;
	render(fdf);
}

void	scale_z(int keycode, t_fdf *fdf)
{
	if (keycode == 61)
		fdf->cam->scale_z += 0.1;
	if (keycode == 45)
		fdf->cam->scale_z -= 0.1;
	render(fdf);
}
