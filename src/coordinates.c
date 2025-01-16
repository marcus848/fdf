/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:02:09 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/14 19:04:52 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_map	*make_map(int fd)
{
	t_map	*map;
	t_point **points;
	char	*line;
	char	**split;
	int		y;

	map = init_map();
	line = ft_strdup("");;
	y = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		split = ft_split(line, ' ');
		if (map->max_x == 0)
			map->max_x = count_arrays((void **) split);
		else if (map->max_x != count_arrays((void **) split))
			return(free_points(points, y), free(map), free(line), free(split), NULL);
		free_points(points, map->max_x);
		points = get_points(split, map->max_x, y);
		print_points(points, map->max_x);
		y++;
	}
	return (map);	
}

int	count_arrays(void **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		i++;
	}
	return i;
}
