/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:13:06 by drohanne          #+#    #+#             */
/*   Updated: 2021/11/06 02:14:35 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	ft_abs(int a)
{
	if (a >= 0)
		return (a);
	return (-a);
}

t_cord	zoom_c(t_cord c, int z)
{
	t_cord	r;

	r = c;
	r.x0 *= z;
	r.x1 *= z;
	r.y0 *= z;
	r.y1 *= z;
	return (r);
}

int	find_zoom(t_map **map)
{
	int	z;

	z = 1200 / (*map)->width / 2;
	if (z == 0)
		z = 1;
	return (z);
}

void	another_kcode(int kcode, t_map *map)
{
	if (kcode == 122)
	{
		map->angle_z += 15;
		map->flag_rotate = 1;
	}
	else if (kcode == 120)
	{
		map->angle_z -= 15;
		map->flag_rotate = 1;
	}
	else if (kcode == 109)
	{
		map->flag_view = 1;
		map->angle_x = 0;
		map->angle_y = 0;
		map->angle_z = 0;
		map->shift_x = 300;
		map->shift_y = 250;
	}
	return ;
}

void	esc_exit(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	mlx_loop_end(map->mlx_ptr);
	free_map(&map);
	exit(EXIT_SUCCESS);
}
