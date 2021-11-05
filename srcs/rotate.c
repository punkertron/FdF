/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 01:57:36 by drohanne          #+#    #+#             */
/*   Updated: 2021/11/05 22:41:02 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>

static double cos_deg(int deg)
{
	double	r;

	r = atan(1) * 4;
	
	r = r * deg / 180;
	return (cos(r));
}

static double sin_deg(int deg)
{
	double	r;

	r = atan(1) * 4;
	r = r * deg / 180;
	return (sin(r));
}

void	angle_x(t_map *map, int *y, int *z)
{
	float	prev_y;

	prev_y = *y;
	*y = (prev_y * cos_deg(map->angle_x)) + (*z * sin_deg(map->angle_x));
	*z = (-prev_y * sin_deg(map->angle_x)) + (*z * cos_deg(map->angle_x));
}

void	angle_y(t_map *map, int *x, int *z)
{
	float	prev_x;

	prev_x = *x;
	*x = (*x * cos_deg(map->angle_y)) + (*z * sin_deg(map->angle_y));
	*z = (-prev_x * sin_deg(map->angle_y)) + (*z * cos_deg(map->angle_y));
}

void	angle_z(t_map *map, int *x, int *y)
{
	float	prev_x;

	prev_x = *x;
	*x = (*x * cos_deg(map->angle_z)) - (*y * sin_deg(map->angle_z));
	*y = (prev_x * sin_deg(map->angle_z)) + (*y * cos_deg(map->angle_z));
}


void	rotate(int *x, int *y, int *z, t_map **map)
{
	if ((*map)->flag_rotate == 1)
	{
		angle_x(*map, y, z);
	// turn_y
		angle_y(*map, x, z);
	// turn_z
		angle_z(*map, x, y);

	}
}