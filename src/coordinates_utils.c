/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:05:27 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/18 19:30:06 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point	**get_points(char **split, t_map *map)
{
	t_point	**points;
	int		i;
	int		increment;
	int		c_size;

	c_size = (map->max_y) * map->max_x;
	points = (t_point **) ft_realloc(map->coordinates,
				  sizeof(t_point *) * c_size, sizeof(t_point *) * (c_size + map->max_x));
	if (!points)
		return (NULL);
	i = 0;
	increment = map->max_y * map->max_x;
	while (i < map->max_x)
	{
		points[i + increment] = (t_point *) malloc(sizeof(t_point));
		if (!points[i + (map->max_y * map->max_x)])
			return (NULL);
		points[i + increment]->x = i;
		points[i + increment]->y = map->max_y;
		points[i + increment]->z = ft_atoi(split[i]);
		points[i + increment]->color = 255;
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
		ft_printf("=============== XYZ =============\n");
		ft_printf("%d° Point:\n", i + 1);
		ft_printf("X: %d\nY: %d\nZ: %d\nColor: %d\n", (int) pt->x, (int) pt->y, (int) pt->z, (int) pt->color);
		ft_printf("=================================\n\n");
		i++;
	}
}
