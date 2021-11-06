/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:28:14 by drohanne          #+#    #+#             */
/*   Updated: 2021/11/06 01:32:59 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/includes/libft.h"

void	map_fill(char **line, t_map **map, int i)
{
	char	**split;
	int		a;

	a = 0;
	split = ft_split(*line, ' ');
	if (split[0] == NULL)
		exit(1);
	if ((*map)->width == -1)
	{
		while (split[a])
			a++;
		(*map)->width = a;
	}
	fill_map(split, map, i);
	free_split(split);
	free(*line);
}

void	default_map(t_map **map)
{
	(*map)->shift_x = 450;
	(*map)->shift_y = 150;
	(*map)->angle = 0.523599;
	(*map)->zoom = find_zoom(map);
	(*map)->flag_rotate = 0;
	(*map)->flag_view = 0;
	(*map)->angle_x = 0;
	(*map)->angle_y = 0;
	(*map)->angle_z = 0;
}

void	free_split(char **split)
{
	int	a;

	a = 0;
	while (split[a])
	{
		free(split[a]);
		a++;
	}
	free(split[a]);
	free(split);
}

void	fill_map(char **split, t_map **map, int i)
{
	int	a;

	(*map)->cord[i] = malloc(sizeof(int) * (*map)->width);
	if ((*map)->cord[i] == NULL)
		ft_exit();
	a = 0;
	while (a < (*map)->width)
	{
		(*map)->cord[i][a] = ft_atoi((const char *)split[a]) * 2;
		if ((*map)->cord[i][a] > (*map)->z_max)
			(*map)->z_max = (*map)->cord[i][a];
		if ((*map)->cord[i][a] < (*map)->z_min)
			(*map)->z_min = (*map)->cord[i][a];
		a++;
	}
}

void	free_map(t_map **map)
{
	int	a;

	a = 0;
	while (a < (*map)->height)
	{
		free((*map)->cord[a]);
		a++;
	}
	free((*map)->mlx_ptr);
	free((*map)->cord);
	free(*map);
}
