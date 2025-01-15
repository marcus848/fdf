/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:10:56 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/14 16:42:40 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <fcntl.h>
#include <stdlib.h>

t_fdf	*init_fdf(char *file_name)
{
	t_fdf	*fdf;
	int		fd;
	char	*line;
	char	**split;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error(1);
	fdf = malloc(sizeof(t_fdf*));
	line = get_next_line(fd);
	split = ft_split(line, ' ');
	ft_printf("numero de colunas (X): %d\n", count_x(split));
	exit (1);

	fdf->map = make_map(fd);
	
	return (fdf);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->coordinates = NULL;
	map->max_x = 0;
	map->max_y = 0;
	return (map);
}
