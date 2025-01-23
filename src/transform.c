/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:18:49 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/22 17:58:18 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	scale(t_line *line, int scale_factor)
{
	line->start.x *= scale_factor;
	line->start.y *= scale_factor;
	line->end.x *= scale_factor;
	line->end.y *= scale_factor;
}

void	offset(t_line *line, t_cam *cam)
{
	line->start.x += cam->offset_x;
	line->start.y += cam->offset_y;
	line->end.x += cam->offset_x;
	line->end.y += cam->offset_y;
}
