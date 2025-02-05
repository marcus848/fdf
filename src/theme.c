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

	normalize_rgb(&r, &g, &b, &result);
	if (result.n_max == result.n_min)
	{
		result.h = 0;
		result.s = 0;
	}
	else
	{
		result.d = result.n_max - result.n_min;
		calculate_hs(&result, r, g, b);
	}
	return (result);
}

void	normalize_rgb(float *r, float *g, float *b, t_hsl *result)
{
	*r /= 255;
	*g /= 255;
	*b /= 255;
	result->n_max = max(max(*r, *g), *b);
	result->n_min = min(min(*r, *g), *b);
	result->l = (result->n_max + result->n_min) / 2;
}

float	hue2rgb(float p, float q, float t)
{
	if (t < 0)
		t += 1;
	if (t > 1)
		t -= 1;
	if (t < 1.0 / 6)
		return (p + (q - p) * 6 * t);
	if (t < 1.0 / 2)
		return (q);
	if (t < 2.0 / 3)
		return (p + (q - p) * (2.0 / 3 - t) * 6);
	return (p);
}

t_rgb	hsl2rgb(float h, float s, float l)
{
	t_rgb	result;
	float	p;
	float	q;

	if (s == 0)
	{
		result.r = l;
		result.g = l;
		result.b = l;
	}
	else
	{
		if (l < 0.5)
			q = l * (1 + s);
		else
			q = l + s - l * s;
		p = 2 * l - q;
		result.r = hue2rgb(p, q, h + 1.0 / 3) * 255;
		result.g = hue2rgb(p, q, h) * 255;
		result.b = hue2rgb(p, q, h - 1.0 / 3) * 255;
	}
	return (result);
}

void	calculate_hs(t_hsl *result, float r, float g, float b)
{
	if (result->l > 0.5)
		result->s = result->d / (2 - result->n_max - result->n_min);
	else
		result->s = result->d / (result->n_max + result->n_min);
	if (result->n_max == r)
	{
		result->h = (g - b) / result->d;
		if (g < b)
			result->h += 6;
	}
	else if (result->n_max == g)
		result->h = (b - r) / result->d + 2;
	else if (result->n_max == b)
		result->h = (r - g) / result->d + 4;
	result->h /= 6;
}
