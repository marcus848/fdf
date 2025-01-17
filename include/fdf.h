/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:08:47 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/16 16:51:26 by marcudos         ###   ########.fr       */
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
	int	**coordinates;
	int	max_x;
	int	max_y;
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
t_map	*init_map(void);

// coordinates
t_map	*make_map(int fd);
int	count_arrays(void **array);
int	process_line(t_map *map, char *line, int y);

// error
void	error(int erro);
void	free_points(t_point **points, int size);

// coordinates_utils
t_point	**get_points(char **split, int size, int y);
void	print_points(t_point **points, int columns);
int	isometric(t_point **points, t_map *map, int size);

// free
void	free_tokens(char **tokens);
void	free_map(t_map *map);
void	free_line_gnl(int fd);


#endif
