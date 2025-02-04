/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:59:50 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/03 21:20:38 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_hsl	rgb2hsl(float r, float g, float b)
{
	t_hsl	result;
	float	n_max;
	float	n_min;
	float	d;

	r /= 255;
	g /= 255;
	b /= 255;
	n_max = max(max(r, g), b);
	n_min = min(min(r, g), b);
	result.h = result.s = result.l = (n_max + n_min) / 2;
	if (max == min)
		result.h = result.s = 0;
	else
	{
		d = n_max - n_min;
		if (result.l > 0.5)
			d /= (2 - n_max - n_min);
		else
			d /= (n_max - n_min);
		if (n_max == r)
			return (result);
	};
	return (result);
}

void	calculate_hs(t_hsl *result, float r, float g, float b, float d)
{
	return ;
}
