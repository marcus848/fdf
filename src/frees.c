/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:32:34 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/03 17:47:05 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <bits/types/cookie_io_functions_t.h>

void	free_coordinates(t_point **coordinates, int x)
{
	while (x--)
		free(coordinates[x]);
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	free_line_gnl(int fd)
{
	while (get_next_line(fd))
		;
	close(fd);
}

void	free_line_gnl_with_line_char(int fd, char *line)
{
	while (1)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
}
