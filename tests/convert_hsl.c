/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hsl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:36:47 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/03 21:01:43 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

#include <stdio.h>

typedef struct rgb {
  int r, g, b;
} RGB;

typedef struct hsl {
  float h, s, l;
} HSL;

HSL rgb2hsl(float r, float g, float b);
float hue2rgb(float p, float q, float t);
RGB hsl2rgb(float h, float s, float l);

int	main(void)
{
	int color = 0x00FFFFFF;
	HSL	c_hsl;
	RGB	c_rgb;

	c_hsl = rgb2hsl((color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
	c_hsl.s = c_hsl.s * 1.1;
	c_hsl.l = c_hsl.l * 0.4;
	printf("H: %f, S: %f, L: %f\n", c_hsl.h, c_hsl.s, c_hsl.l);
	c_rgb = hsl2rgb(c_hsl.h, c_hsl.s, c_hsl.l);
	printf("R: %d, G: %d, B: %d\n", (int)c_rgb.r, (int)c_rgb.g, (int)c_rgb.b);
}
HSL	rgb2hsl(float r, float g, float b)
{
	HSL		result;
	float		max;
	float		min;
	float		d;

	r /= 255;
	g /= 255;
	b /= 255;
	max = MAX(MAX(r, g), b);
	min = MIN(MIN(r, g), b);
	result.l = (max + min) / 2;
	if (max == min)
	{
		result.h = 0;
		result.s = 0;
	}
	else
	{
		d = max - min;
		if (result.l > 0.5)
			result.s = d / (2 - max - min);
		else
			result.s = d / (max + min);
		if (max == r)
		{
			result.h = (g - b) / d;
			if (g < b)
				result.h += 6;
		}
		else if (max == g)
			result.h = (b - r) / d + 2;
		else if (max == b)
			result.h = (r - g) / d + 4;
		result.h /= 6;
	}
	return (result);
}

////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////

RGB	hsl2rgb(float h, float s, float l)
{
	RGB		result;
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

// /*
//  * Converts an RGB color value to HSL. Conversion formula
//  * adapted from http://en.wikipedia.org/wiki/HSL_color_space.
//  * Assumes r, g, and b are contained in the set [0, 255] and
//  * returns HSL in the set [0, 1].
//  */
// HSL rgb2hsl(float r, float g, float b) {
//   
//   HSL result;
//   
//   r /= 255;
//   g /= 255;
//   b /= 255;
//   
//   float max = MAX(MAX(r,g),b);
//   float min = MIN(MIN(r,g),b);
//   
//   result.h = result.s = result.l = (max + min) / 2;
//
//   if (max == min) {
//     result.h = result.s = 0; // achromatic
//   }
//   else {
//     float d = max - min;
//     result.s = (result.l > 0.5) ? d / (2 - max - min) : d / (max + min);
//     
//     if (max == r) {
//       result.h = (g - b) / d + (g < b ? 6 : 0);
//     }
//     else if (max == g) {
//       result.h = (b - r) / d + 2;
//     }
//     else if (max == b) {
//       result.h = (r - g) / d + 4;
//     }
//     
//     result.h /= 6;
//   }
//
//   return result;
//   
// }
//
// ////////////////////////////////////////////////////////////////////////
//
// /*
//  * Converts an HUE to r, g or b.
//  * returns float in the set [0, 1].
//  */
// float hue2rgb(float p, float q, float t) {
//
//   if (t < 0) 
//     t += 1;
//   if (t > 1) 
//     t -= 1;
//   if (t < 1./6) 
//     return p + (q - p) * 6 * t;
//   if (t < 1./2) 
//     return q;
//   if (t < 2./3)   
//     return p + (q - p) * (2./3 - t) * 6;
//     
//   return p;
//   
// }
//
// /*
//  * Converts an HSL color value to RGB. Conversion formula
//  * adapted from http://en.wikipedia.org/wiki/HSL_color_space.
//  * Assumes h, s, and l are contained in the set [0, 1] and
//  * returns RGB in the set [0, 255].
//  */
// RGB hsl2rgb(float h, float s, float l) {
//
//   RGB result;
//   
//   if(0 == s) {
//     result.r = result.g = result.b = l; // achromatic
//   }
//   else {
//     float q = l < 0.5 ? l * (1 + s) : l + s - l * s;
//     float p = 2 * l - q;
//     result.r = hue2rgb(p, q, h + 1./3) * 255;
//     result.g = hue2rgb(p, q, h) * 255;
//     result.b = hue2rgb(p, q, h - 1./3) * 255;
//   }
//
//   return result;
//
// }
