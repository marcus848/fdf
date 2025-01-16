/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:05:27 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/16 16:00:43 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdlib.h>

t_point	**get_points(char **split, int size, int y)
{
	t_point	**points;
	int		i;

	points = (t_point **) malloc(sizeof(t_point *) * size);
	if (!points)
		return (NULL);
	i = 0;
	while (i < size)
	{
		points[i] = (t_point *) malloc(sizeof(t_point));
		if (!points[i])
			return (NULL);
		points[i]->x = i + 1;
		points[i]->y = y;
		points[i]->z = ft_atoi(split[i]);
		points[i]->color = 255;
		i++;
	}
	return (points);
}

void	print_points(t_point **points, int columns)
{
	t_point	*pt;
	int		i;

	i = 0;
	while (i < columns)
	{
		pt = points[i];
		ft_printf("==============================\n");
		ft_printf("%d° Point:\n", i + 1);
		ft_printf("X: %d\nY: %d\nZ: %d\nColor: %d\n", (int) pt->x, (int) pt->y, (int) pt->z, (int) pt->color);
		ft_printf("==============================\n\n");
		i++;
	}
}
