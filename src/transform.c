/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:18:49 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/21 19:33:58 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void isometric(t_fdf *fdf)
{
    int x, y;
    t_point *line;

    y = 0;
    while (y < fdf->map->max_y)
    {
        x = 0;
        while (x < fdf->map->max_x)
        {
            // Pegando o ponto original da matriz
            line = &fdf->map->coordinates[x][y];

            // Calculando a nova coordenada x e y para a projeção isométrica
            float new_x = (line->x - line->y) * cos(ANG_30);
            float new_y = (line->x + line->y) * cos(ANG_30) - line->z;

            // Atualizando as coordenadas diretamente no ponto
            line->x = new_x;
            line->y = new_y;

            x++;
        }
        y++;
    }
}

