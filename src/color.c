/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:17:29 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/03 17:47:50 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

float	fraction(float start, float end, float current)
{
	if (start != end)
		return ((current - start) / (end - start));
	return (0.0f);
}

float	calculate_fraction(int x, int y, t_point *start, t_point *end)
{
	int	dx;
	int	dy;

	x = 0;
	dx = end->x - start->x;
	dy = end->y - start->y;
	if (absolute(dx) > absolute(dy))
		return (fraction(start->x, end->x, x));
	return (fraction(start->y, end->y, y));
}

int	interpolate_colors(int color1, int color2, float fraction)
{
	t_colors	colors;
	int			r;
	int			g;
	int			b;

	colors.r1 = (color1 >> 16) & 0xFF;
	colors.g1 = (color1 >> 8) & 0xFF;
	colors.b1 = color1 & 0xFF;
	colors.r2 = (color2 >> 16) & 0xFF;
	colors.g2 = (color2 >> 8) & 0xFF;
	colors.b2 = color2 & 0xFF;
	r = colors.r1 + (int)((colors.r2 - colors.r1) * fraction);
	g = colors.g1 + (int)((colors.g2 - colors.g1) * fraction);
	b = colors.b1 + (int)((colors.b2 - colors.b1) * fraction);
	return ((r << 16) | (g << 8) | b);
}
