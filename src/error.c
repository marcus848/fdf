/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:39:07 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/14 16:40:51 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	error(int erro)
{
	if (erro == 1)
		ft_printf("Message 1");
	if (erro == 2)
		ft_printf("Message 2");
	if (erro == 3)
		ft_printf("Message 3");
	if (erro == 4)
		ft_printf("Message 4");
	if (erro == 5)
		ft_printf("Message 5");
	exit (1);
}

void	free_points(t_point **points, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(points[i++]);
	free(points);
	*points = NULL;
}
