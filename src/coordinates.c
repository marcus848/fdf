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
	char	*line;
	char	**split;

	map = init_map();
	line = ft_strdup("");;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		split = ft_split(line, ' ');
	}
	return (map);	
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
