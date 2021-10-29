/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dunstan <dunstan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:50:32 by drohanne          #+#    #+#             */
/*   Updated: 2021/10/30 00:24:28 by dunstan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# include "../libft/includes/libft.h"
# include "get_next_line.h"

typedef struct s_map
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		**cord;
	int		height;
	int		width;
} t_map;

void	fdf(char *argv);

t_map	*init_map(char *argv);
void	get_heght_width(t_map **map, char *argv);
void	map_fill(char **line, t_map **map, int i);
void	fill_map(char **split, t_map **map, int i);

int 	ft_abs(int a);

void	free_split(char **split);
void	free_map(t_map **map);
void	ft_exit(void);

#endif