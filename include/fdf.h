/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:08:47 by marcudos          #+#    #+#             */
/*   Updated: 2025/01/22 20:30:37 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// Libs
# include "../mlx/mlx.h"
# include "../libft/include/libft.h"
# include <math.h>
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
	t_point	start;
	t_point	end;
	float	transform_z;
}	t_line;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_line	*line;
}	t_img;

typedef struct s_delta
{
	double	deltax;
	double	deltay;
	double	deltacolor;
	double	x;
	double	y;
	double	c;
	int		pixels;
}	t_delta;

typedef struct s_cam
{
	float	scale_factor;
	float	scale_z;
	float	offset_y;
	float	offset_x;
}	t_cam;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	int		win_x;
	int		win_y;
	t_map	*map;
	t_img	*img;
	t_cam	*cam;
}	t_fdf;

// main
int	close_window(t_fdf *fdf);

// init_structs
t_fdf	*init_fdf(char *file_name);
t_map	*init_map(void);
t_img	*init_img(void *mlx);
t_line	*init_line(t_point start, t_point end, t_fdf *fdf);
t_cam	*init_cam(t_fdf *fdf);

// init_utils
int	get_dimensions(char *file_name, t_map *map, t_fdf *fdf);
t_point	**init_coordinates(int height, int width);
t_fdf	*start_fdf(void);

// map
t_map	*make_map(char *file_name, t_fdf *fdf);

// map_utils
void	get_points(char *file_name, t_map *map);
void	fill_point(char *point, t_point *coordinate, t_map *map, int coord[2]);
void	center_to_origin(t_map *map);
int		scale_points(t_map *map);

// error
void	error(int erro, t_fdf *fdf);

// frees
void	free_coordinates(t_point **coordinates, int x);
void	free_tokens(char **tokens);

// free_structs
void	free_all(t_fdf *fdf);
void	free_map(t_map *map);
t_cam	*free_cam(t_cam *cam);
t_img	*free_img(t_img *img, void *mlx_ptr, void *img_ptr);

// utils
float	max(float a, float b);
float	absolute(float nbr);
float	min(float a, float b);

// render
void	render(t_fdf *fdf);
void	render_line(t_fdf *fdf, t_point start, t_point end);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	ft_drawline(t_point point1, t_point point2, t_fdf *fdf);

// transform
void	isometric(t_line *line);
void	scale(t_line *line, int scale_factor);
void	offset(t_line *line, t_cam *cam);

// utils
float	min(float a, float b);
float	absolute(float nbr);
float	max(float a, float b);

#endif
