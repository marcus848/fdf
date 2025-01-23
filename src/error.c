/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:39:07 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/22 21:08:58 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	error(int erro, t_fdf *fdf)
{
	int	y;

	if (erro == 3)
		y = fdf->win_y + 1;
	if (erro != 3)
		free_all(fdf);
	if (erro == 1)
		ft_printf("error ao ler o arquivo\n");
	if (erro == 2)
		ft_printf("Erro ao iniciar o map\n");
	if (erro == 3)
		ft_printf("Numero de colunas incorreto na coluna: %d\n", y);
	if (erro == 4)
		ft_printf("erro durante o make map\n");
	if (erro == 5)
		ft_printf("erro ao iniciar as coordenadas\n");
	if (erro == 6)
		ft_printf("erro ao iniciar a imagem\n");
	if (erro == 7)
		ft_printf("erro ao iniciar a camera\n");
	exit (erro);
}
