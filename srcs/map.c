/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:28:14 by drohanne          #+#    #+#             */
/*   Updated: 2021/10/24 19:03:33 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		ft_exit();
	return (map);
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

void	fill_map(char **split, t_map *map, int i)
{
	int	a;

	a = 0;
	while (split[a])
		a++;
	map->cord[i] = malloc(sizeof(int) * a);
	if (map->cord[i] == NULL)
		ft_exit(); 
	a = 0;
	while (split[a])
	{
		map->cord[i][a] = ft_atoi((const char *)split[a]);
		a++;
	}
}

void	free_map(t_map **map)
{
	int	a;

	a = 0;
	while ((*map)->cord[a])
	{
		free((*map)->cord[a]);
		a++;
	}
	free((*map)->cord);
	(*map)->cord= NULL;
	free(*map);
	*map = NULL;
}
