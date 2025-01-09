/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:29:45 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/09 12:16:02 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

int	f_close(int keycode, t_vars *vars);

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 680, 360, "hook");
	mlx_hook(vars.win, 2, 1L<<0, f_close, &vars);
	mlx_loop(vars.mlx);
}

int	f_close(int keycode, t_vars *vars)
{
	// mlx_destroy_window(vars->mlx, vars->win);
	ft_printf("%c\n", (char) keycode);
	return (0);
}
