/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:50:32 by drohanne          #+#    #+#             */
/*   Updated: 2021/10/24 19:03:44 by drohanne         ###   ########.fr       */
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
} t_map;

void	fdf(char *argv);
void	ft_exit(void);
void	fill_map(char **split, t_map *map, int i);
void	free_split(char **split);
t_map	*init_map(void);
void	free_map(t_map **map);
void	map_fill(char **line, t_map *map, int i);

#endif