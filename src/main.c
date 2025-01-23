/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:35:02 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/23 19:05:43 by marcudos         ###   ########.fr       */
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
	mlx_hook(fdf->win, 2, 1L<<0, &key_press, fdf);
	mlx_loop(fdf->mlx);
	free(fdf);
	return (1);
}

int key_press(int keycode, t_fdf *fdf)
{
	if (keycode == 65307)
		close_window(fdf);
	if (keycode == 65362)
		translate(keycode, fdf);
	if (keycode == 65364)
		translate(keycode, fdf);
	if (keycode == 65361)
		translate(keycode, fdf);
	if (keycode == 65363)
		translate(keycode, fdf);
	if (keycode == 61 || keycode == 45)
		scale_z(keycode, fdf);
	return (0);
}

int	close_window(t_fdf *fdf)
{
	free_all(fdf);
	return (0);
}
