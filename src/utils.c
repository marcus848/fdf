/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:09:09 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/03 19:46:47 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

float	min(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

float	absolute(float nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

float	max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	reset_angles(t_cam *cam)
{
	cam->gamma = 0;
	cam->beta = 0;
	cam->alpha = 0;
}
