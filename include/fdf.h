/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:08:47 by marcudos          #+#    #+#             */
/*   Updated: 2025/02/03 21:03:33 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// Libs
# include "../mlx/mlx.h"
# include "../libft/include/libft.h"
# include <math.h>
# include "keys.h"

// defines
# define WIN_WIDTH 1200
# define WIN_HEIGHT 900
# define MAX_PIXELS 1080000

# define ANG_30 0.52359877
# define ANG_1	0.01745329

# define BACKGROUND_DEFAULT 0x000000
# define LINE_DEFAULT 0xffffff

// enum
enum e_project
{
	ISOMETRIC,
	SIDE_PARALLEL,
	TOP,
};

// Structs
typedef struct s_hsl
{
	float	h;
	float	s;
	float	l;
	float	n_max;
	float	n_min;
	float	d;
}	t_hsl;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

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
	double	alpha;
	double	beta;
	double	gamma;
	int		type_project;
}	t_cam;

typedef struct s_menu
{
	int		its_open;
	void	*sidebar_img;
	char	*name;
}	t_menu;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	int		win_x;
	int		win_y;
	t_map	*map;
	t_img	*img;
	t_cam	*cam;
	int		theme;
	t_menu	*menu;
}	t_fdf;

typedef struct s_colors
{
	int	r1;
	int	g1;
	int	b1;
	int	r2;
	int	g2;
	int	b2;
}	t_colors;

// main
int		close_window(t_fdf *fdf);
int		key_press(int keycode, t_fdf *fdf);
int		mouse_press(int button, int x, int y, t_fdf *fdf);

// init_structs
t_fdf	*init_fdf(char *file_name);
t_map	*init_map(void);
t_img	*init_img(void *mlx);
t_line	*init_line(t_point start, t_point end, t_fdf *fdf);
t_cam	*init_cam(t_fdf *fdf);

// init_utils
void	get_dimensions(char *file_name, t_map *map, t_fdf *fdf);
t_point	**init_coordinates(int height, int width);
t_fdf	*start_fdf(void);
t_menu	*init_menu(void);

// map
t_map	*make_map(char *file_name, t_fdf *fdf);
void	get_points(char *file_name, t_map *map);
void	fill_point(char *point, t_point *coordinate, t_map *map, int coord[2]);
void	center_to_origin(t_map *map);
int		scale_points(t_map *map);

// error
void	error(int err, t_fdf *fdf);

// frees
void	free_coordinates(t_point **coordinates, int x);
void	free_tokens(char **tokens);
void	free_line_gnl(int fd);
void	free_line_gnl_with_line_char(int fd, char *line);

// free_structs
void	free_all(t_fdf *fdf);
void	free_map(t_map *map);
void	free_menu(t_fdf *fdf);

// render
void	render(t_fdf *fdf);
void	render_line(t_fdf *fdf, t_point start, t_point end);

// draw
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	drawline(t_point point1, t_point point2, t_fdf *fdf);
void	adjust_lightness(t_hsl *hsl);
void	adjust_color(t_hsl *hsl);
int		getpixels(t_point point1, t_point point2);

// transform
void	scale(t_line *line, int scale_factor);
void	offset(t_line *line, t_cam *cam);

// projections
void	project(t_cam *cam, t_line *line);
void	isometric(t_line *line);
void	side_parallel(t_line *line);

// utils
float	min(float a, float b);
float	absolute(float nbr);
float	max(float a, float b);
void	reset_angles(t_cam *cam);

// color
float	fraction(float start, float end, float current);
float	calculate_fraction(int x, int y, t_point *start, t_point *end);
int		interpolate_colors(int color1, int color2, float fraction);
int		change_color(t_point point);
int		get_color(int z, int z_min, int z_max);

// hooks
void	translate(int keycode, t_fdf *fdf);
void	scale_z(int keycode, t_fdf *fdf);
void	zoom(int keycode, t_fdf *fdf);

// hooks 2
void	rotate_hook(int keycode, t_fdf *fdf);
void	change_projection(int keycode, t_fdf *fdf);
void	change_theme(int keycode, t_fdf *fdf);

// rotate
void	rotate(t_cam *cam, t_line *line);
void	rotate_x(t_line *line, double angle);
void	rotate_y(t_line *line, double angle);
void	rotate_z(t_line *line, double angle);

// theme
void	calculate_hs(t_hsl *result, float r, float g, float b);
void	normalize_rgb(float *r, float *g, float *b, t_hsl *result);
t_hsl	rgb2hsl(float r, float g, float b);
t_rgb	hsl2rgb(float h, float s, float l);
float	hue2rgb(float p, float q, float t);

// menu
void	make_menu(t_fdf *fdf);
void	change_menu(t_fdf *fdf);

#endif
