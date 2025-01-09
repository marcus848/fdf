/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:26:02 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/09 12:42:16 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close_window(t_vars *vars)
{
	(void)vars; // Se não usar a estrutura, evita warning
	ft_printf("Window Closed\n");
	exit (0);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_hook(vars.win, 17, 0, close_window, &vars); // 6 = MotionNotify para movimento do mouse
	mlx_loop(vars.mlx);
}

