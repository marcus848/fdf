/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:39:07 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/22 21:08:58 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	error(int err, t_fdf *fdf)
{
	int	y;

	if (err == 3)
	{
		y = fdf->map->max_y + 1;
		free(fdf->map);
		free(fdf);
	}
	if (err != 3)
		free_all(fdf);
	if (err == 1)
		ft_printf("Error reading the file\n");
	if (err == 2)
		ft_printf("Error initializing the map\n");
	if (err == 3)
		ft_printf("Incorrect number of columns at column: %d\n", y);
	if (err == 4)
		ft_printf("Error during map creation\n");
	if (err == 5)
		ft_printf("Error initializing coordinates\n");
	if (err == 6)
		ft_printf("Error initializing the image\n");
	if (err == 7)
		ft_printf("Error initializing the camera\n");
	exit (err);
}
