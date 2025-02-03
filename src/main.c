/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:35:02 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/03 19:32:58 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int ac, char **av)
{
	char	*file_name;
	t_fdf	*fdf;

	if (ac != 2)
		exit(1);
	file_name = av[1];
	fdf = init_fdf(file_name);
	render(fdf);
	mlx_hook(fdf->win, 17, 0, &close_window, fdf);
	mlx_hook(fdf->win, 2, 1L << 0, &key_press, fdf);
	mlx_loop(fdf->mlx);
	free(fdf);
	return (1);
}

int	key_press(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		close_window(fdf);
	if (keycode >= KEY_LEFT && keycode <= KEY_DOWN)
		translate(keycode, fdf);
	if (keycode == KEY_Z || keycode == KEY_X)
		scale_z(keycode, fdf);
	if (keycode == KEY_MINUS || keycode == KEY_PLUS)
		zoom(keycode, fdf);
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A ||
		keycode == KEY_D || keycode == KEY_Q || keycode == KEY_E)
		rotate_hook(keycode, fdf);
	if (keycode == KEY_T || keycode == KEY_I || keycode == KEY_P)
		change_projection(keycode, fdf);
	render(fdf);
	return (0);
}

int	close_window(t_fdf *fdf)
{
	free_all(fdf);
	return (0);
}
