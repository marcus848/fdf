/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:26:02 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/09 12:49:20 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	mouse_move(int x, int y, t_vars *vars)
{
	(void)vars; // Se não usar a estrutura, evita warning
	ft_printf("Mouse position: x = %d, y = %d\n", x, y);
	mlx_pixel_put(vars->mlx, vars->win, x, y, 0x00FF0000);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_hook(vars.win, 6, 1L<<6, mouse_move, &vars); // 6 = MotionNotify para movimento do mouse
	mlx_loop(vars.mlx);
}

