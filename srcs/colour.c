/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:44:14 by drohanne          #+#    #+#             */
/*   Updated: 2021/11/06 18:07:51 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_col(t_map **map)
{
	int	i;
	int	a;

	i = 0;
	(*map)->col = malloc(sizeof(int *) * (*map)->height);
	if ((*map)->col == NULL)
		ft_exit();
	while (i < (*map)->height)
	{
		(*map)->col[i] = malloc(sizeof(int) * (*map)->width);
		if ((*map)->col[i] == NULL)
			ft_exit();
		a = 0;
		while (a < (*map)->width)
		{
			(*map)->col[i][a] = default_color((*map)->cord[i][a], *map);
			a++;
		}
		i++;
	}
}

static float	percent(int start, int end, int current)
{
	float	placement;
	float	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

int	default_color(int z, t_map *map)
{
	float	percentage;

	percentage = percent(map->z_min, map->z_max, z);
	if (percentage < 0.2)
		return (0xE0FFFF);
	else if (percentage < 0.4)
		return (0x40E0D0);
	else if (percentage < 0.6)
		return (0x4682B4);
	else if (percentage < 0.8)
		return (0x00BFFF);
	else
		return (0x9400D3);
}

static int	get_light(int start, int end, float percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	ft_color(t_cord t, t_bran b)
{
	int		red;
	int		green;
	int		blue;
	float	percentage;

	if (b.col0_init == b.col1_init)
		return (b.col0_init);
	if (b.dx > b.dy)
		percentage = percent(b.start_x, t.x1, t.x0);
	else
		percentage = percent(b.start_y, t.y1, t.y0);
	red = get_light((b.col0_init >> 16) & 0xFF, (b.col1_init >> 16) & 0xFF,
			percentage);
	green = get_light((b.col0_init >> 8) & 0xFF, (b.col1_init >> 8) & 0xFF,
			percentage);
	blue = get_light(b.col0_init & 0xFF, b.col1_init & 0xFF,
			percentage);
	return ((red * 65536) + (green * 256) + blue);
}
