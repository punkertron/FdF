/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:13:06 by drohanne          #+#    #+#             */
/*   Updated: 2021/11/04 16:13:11 by drohanne         ###   ########.fr       */
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

int	ft_colour(int i)
{
	if (i == 0)
		return (0xFFFFFF);
	if (i < 50)
		return (i * 120000);
	else if (i < 200)
		return (10000 + i * 10000);
	else
		return (i);
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
	fprintf(stderr, "width = %d\n", (*map)->width);
	fprintf(stderr, "height = %d\n", (*map)->height);
	(void) map;
	return (40);
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
