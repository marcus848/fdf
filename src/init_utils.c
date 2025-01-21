/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:06:53 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/21 15:07:52 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point	**init_coordinates(int height, int width)
{
	t_point	**coordinates;
	int		y;
	int		x;

	coordinates = malloc(width * sizeof(t_point *));
	if (!coordinates)
		return (NULL);
	x = 0;
	while (x < width)
	{
		coordinates[x] = malloc(height * sizeof(t_point));
		if (!coordinates[x])
			return (NULL);
		y = 0;
		while (y < height)
		{
			coordinates[x][y].x = 0;
			coordinates[x][y].y = 0;
			coordinates[x][y].z = 0;
			coordinates[x][y].color = 0;
			y++;
		}
		x++;
	}
	return (coordinates);
}

void	get_dimensions(char *file_name, t_map *map)
{
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error(1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (map->max_x == 0)
			map->max_x = ft_count_words(line);
		else if (map->max_x != ft_count_words(line))
		{
			free(line);
			error(1);
		}
		free (line);
		map->max_y++;
	}
	close(fd);
}
