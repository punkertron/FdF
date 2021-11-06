/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:50:32 by drohanne          #+#    #+#             */
/*   Updated: 2021/11/06 02:14:42 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		**cord;
	int		z_min;
	int		z_max;
	int		height;
	int		width;
	int		zoom;
	float	angle;
	int		shift_x;
	int		shift_y;
	void	*img;
	int		flag_view;
	int		flag_rotate;
	int		angle_x;
	int		angle_y;
	int		angle_z;
}	t_map;

typedef struct s_bran
{
	int	dx;
	int	dy;
	int	signx;
	int	signy;
	int	error;
	int	error2;
	int	start_x;
	int	start_y;
}	t_bran;

typedef struct s_cord
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	z0;
	int	z1;
	int	colour0;
	int	colour1;
}	t_cord;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

void	fdf(char *argv);

t_map	*init_map(char *argv);
void	default_map(t_map **map);
void	get_height_width(t_map **map, char *argv);
void	map_fill(char **line, t_map **map, int i);
void	fill_map(char **split, t_map **map, int i);

void	pre_draw(t_map **map);
void	brasenham(t_cord c, t_map **map, t_img *img);

void	put_instructions(t_map **map);

void	rotate(int *x, int *y, int *z, t_map **map);

int		ft_abs(int a);
t_cord	zoom_c(t_cord c, int z);
int		find_zoom(t_map **map);
void	another_kcode(int kcode, t_map *map);

double	cos_deg(int deg);
double	sin_deg(int deg);

int		default_color(int z, t_map *map);
int		ft_color(t_cord t, t_bran b);

void	esc_exit(t_map *map);
void	free_split(char **split);
void	free_map(t_map **map);
void	ft_exit(void);

#endif