/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:50:32 by drohanne          #+#    #+#             */
/*   Updated: 2021/11/04 15:35:23 by drohanne         ###   ########.fr       */
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
	int		height;
	int		width;
	int		zoom;
	float	angle;
	int		colour;
	int		shift_x;
	int		shift_y;
	void	*img;
}	t_map;

typedef struct s_bran
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	signx;
	int	signy;
	int	error;
	int	error2;
}	t_bran;

typedef struct s_cord
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
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
//void	my_mlx_pixel_put(t_img *img, int x, int y, int colour);

t_map	*init_map(char *argv);
void	default_map(t_map **map);
void	get_heght_width(t_map **map, char *argv);
void	map_fill(char **line, t_map **map, int i);
void	fill_map(char **split, t_map **map, int i);

void	pre_draw(t_map **map);
void	draw_lines(t_map **map, t_img *img);
void	brasenham(t_cord c, t_map **map, t_img *img);

void	esc_exit(t_map *map);
void	my_mlx_pixel_put(t_img *img, int x, int y, int colour);
void	fill_b(t_bran *b, t_cord *t);
void	add_shift(t_cord *t, t_map **map);
void	isometric(t_cord *t, t_map **map);

int		find_zoom(t_map **map);
t_cord	zoom_c(t_cord c, int z);

int		ft_abs(int a);
int		ft_colour(int i);

void	free_split(char **split);
void	free_map(t_map **map);
void	ft_exit(void);

#endif