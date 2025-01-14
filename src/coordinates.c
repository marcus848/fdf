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

t_map	*make_coordinates(int fd)
{
	t_map	*map;
	char	*line;
	char	**split;

	map = init_map();
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		if (!map->max_x)
			map->max_x = count_x(split);
		else if (count_x(split) != map->max_x)
			error(3);
	}
		
}

int	count_x(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		i++;
	}
	return i;
}
