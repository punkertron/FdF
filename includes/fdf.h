/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dunstan <dunstan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:50:32 by drohanne          #+#    #+#             */
/*   Updated: 2021/10/31 23:23:12 by dunstan          ###   ########.fr       */
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
	int		colour;
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

void	fdf(char *argv);

t_map	*init_map(char *argv);
void	get_heght_width(t_map **map, char *argv);
void	map_fill(char **line, t_map **map, int i);
void	fill_map(char **split, t_map **map, int i);

void	draw(t_map **map);
void	draw_lines(t_map **map);
void	brasenham(t_cord c, t_map **map);
int		find_zoom(t_map **map);
t_cord	zoom_c(t_cord c, int z);

int		ft_abs(int a);
int		ft_colour(int i);

void	free_split(char **split);
void	free_map(t_map **map);
void	ft_exit(void);

#endif