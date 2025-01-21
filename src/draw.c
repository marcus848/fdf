/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:14:58 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/21 17:52:18 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	bresenham(t_fdf *fdf, t_line *line)
{
	int	err;   // Variável local para calcular o erro
	int	err2;  // Variável para armazenar o erro dobrado

	// Calcula o erro inicial
	err = line->dx - line->dy;

	while (1)
	{
		// Desenha o pixel atual
		mlx_pixel_put(fdf->mlx, fdf->win, (int)line->p1.x, (int)line->p1.y, 
                      (line->p1.color == -1 ? 0xFFFFFF : line->p1.color));

		// Verifica se chegou ao ponto final
		if ((int)line->p1.x == (int)line->p2.x && (int)line->p1.y == (int)line->p2.y)
			break;

		// Atualiza o erro e decide o próximo ponto
		err2 = 2 * err;  // Dobra o erro atual
		if (err2 > -line->dy)
		{
			err -= line->dy;
			line->p1.x += line->sx;
		}
		if (err2 < line->dx)
		{
			err += line->dx;
			line->p1.y += line->sy;
		}
	}
}

