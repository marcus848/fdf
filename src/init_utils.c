/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:05:27 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/14 19:04:52 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point	**get_points(char **split, int size, int y)
{
	t_point	**points;
	char	**point;
	int		i;

	points = malloc(sizeof(t_point *) * size);
	if (!points)
		return (NULL);
	i = 0;
	while (i < size)
	{
		points[i] = malloc(sizeof(t_point *));
		if (!points[i])
		{
			while (i > 0)
				free(points[--i]);
			free(points);
			return (NULL);
		}
		point = ft_split(split[i], ',');
		points[i]->x = i + 1;
		points[i]->y = y;
		points[i]->z = ft_atoi(point[0]);
		points[i]->color = 255;
		i++;
	}
	return (points);
}

void	print_points(t_point **points, int size)
{
	int	i;
	t_point	*pt;

	i = 0;
	while (i < size)
	{
		pt = points[i];
		ft_printf("==============================\n");
		ft_printf("%d° Point:\n", i + 1);
		ft_printf("X: %d\nY: %d\nZ: %d\nColor: %d\n",(int)pt->x, (int)pt->y, (int)pt->z, (int)pt->color);
		ft_printf("==============================\n\n");
		i++;
	}
}
