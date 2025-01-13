/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:08:47 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/13 18:45:09 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// defines
#define WIN_WIDTH 1200
#define WIN_HEIGHT 900

// Libs
#include "../mlx/mlx.h"
#include "../libft/include/libft.h"
#include <math.h>
#include <string.h>

// Structs
typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_map
{
	int	**coordinate;
}	t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	t_map	*map;
}	t_fdf;

// init_fdf
t_fdf	*init_fdf(char *file_name);

#endif
