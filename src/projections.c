/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:19:46 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/03 19:44:15 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	project(t_cam *cam, t_line *line)
{
	if (cam->type_project == ISOMETRIC)
		isometric(line);
	if (cam->type_project == SIDE_PARALLEL)
		side_parallel(line);
	if (cam->type_project == TOP)
		return ;
}

void	isometric(t_line *line)
{
	t_point	new_start;
	t_point	new_end;

	new_start.x = (line->start.x - line->start.y) * cos(ANG_30);
	new_start.y = (line->start.x + line->start.y) * sin(ANG_30) - line->start.z;
	line->start.x = new_start.x;
	line->start.y = new_start.y;
	new_end.x = (line->end.x - line->end.y) * cos(ANG_30);
	new_end.y = (line->end.x + line->end.y) * sin(ANG_30) - line->end.z;
	line->end.x = new_end.x;
	line->end.y = new_end.y;
}

void	side_parallel(t_line *line)
{
	t_point	new_start;
	t_point	new_end;

	new_start.x = line->start.y;
	new_start.y = -line->start.z;
	line->start.x = new_start.x;
	line->start.y = new_start.y;
	new_end.x = line->end.y;
	new_end.y = -line->end.z;
	line->end.x = new_end.x;
	line->end.y = new_end.y;
}
