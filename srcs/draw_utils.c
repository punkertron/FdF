/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:13:06 by drohanne          #+#    #+#             */
/*   Updated: 2021/11/06 14:59:42 by drohanne         ###   ########.fr       */
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

void	zoom_c(t_cord *t, t_map *map)
{
	int	z;
	int	z1;

	z = map->zoom;
	z1 = z / 2;
	t->z0 = map->cord[t->y0][t->x0] * z1;
	t->z1 = map->cord[t->y1][t->x1] * z1;
	t->x0 *= z;
	t->x1 *= z;
	t->y0 *= z;
	t->y1 *= z;
	return ;
}

int	find_zoom(t_map **map)
{
	int	z;

	z = 1200 / (*map)->width / 2;
	if (z == 0)
		z = 1;
	return (z);
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
