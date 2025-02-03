/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:06:53 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/03 17:43:14 by marcudos         ###   ########.fr       */
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
			return (free_coordinates(coordinates, x), NULL);
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

void	get_dimensions(char *file_name, t_map *map, t_fdf *fdf)
{
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error(1, fdf);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (map->max_x == 0)
			map->max_x = ft_count_words(line);
		else if (map->max_x != ft_count_words(line))
		{
			fdf->map = map;
			free_line_gnl_with_line_char(fd, line);
			close(fd);
			error(3, fdf);
		}
		free (line);
		map->max_y++;
	}
	close(fd);
}

t_fdf	*start_fdf(void)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->img = NULL;
	fdf->cam = NULL;
	fdf->map = NULL;
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->win_x = 0;
	fdf->win_y = 0;
	return (fdf);
}
