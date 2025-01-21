/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:08:47 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/21 19:30:58 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// Libs
# include "../mlx/mlx.h"
# include "../libft/include/libft.h"
# include <math.h>
# include <string.h>
# include "colors.h"

// defines
# define WIN_WIDTH 1200
# define WIN_HEIGHT 900

# define ANG_30 0.52359877
# define SCALE 30

# define BACKGROUND_DEFAULT C_BLACK
# define LINE_DEFAULT C_WHITE
# define C_TEXT C_WHITE

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
	t_point	**coordinates;
	int		max_x;
	int		max_y;
	int		max_z;
	int		min_z;
}	t_map;

typedef struct s_line
{
	t_point	p1;
	t_point	p2;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
}	t_line;

typedef struct s_img
{
	void	*img;
	char	*buffer;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_line	*line;
}	t_img;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	int		win_x;
	int		win_y;
	float		scale;
	t_map	*map;
	t_line	*line;
}	t_fdf;

// init_structs
t_fdf	*init_fdf(char *file_name);
t_map	*init_map(void);
t_img	*init_img(void *mlx);
t_line	*init_line(t_point start, t_point end);

// init_utils
void	get_dimensions(char *file_name, t_map *map);
t_point	**init_coordinates(int height, int width);

// map
t_map	*make_map(char *file_name);

// map_utils
void	get_points(char *file_name, t_map *map);
void	fill_point(char *point, t_point *coordinate, t_map *map, int x, int y);
void	print_points(t_point **points, int columns);
void	center_to_origin(t_map *map);
int	scale(t_map *map);

// error
void	error(int erro);

// free
void	free_tokens(char **tokens);
void	free_map(t_map *map);
void	free_line_gnl(int fd);

// utils
float	max(float a, float b);
float	absolute(float nbr);
float	min(float a, float b);

// render
void	render(t_fdf *fdf);
void	render_line(t_fdf *fdf, t_point start, t_point end);

// transform
void	isometric(t_fdf *fdf);

// draw
void	bresenham(t_fdf *fdf, t_line *line);

// utils
float	min(float a, float b);
float	absolute(float nbr);
float	max(float a, float b);


#endif
