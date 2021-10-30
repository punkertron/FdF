/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dunstan <dunstan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:53:34 by drohanne          #+#    #+#             */
/*   Updated: 2021/10/30 17:42:01 by dunstan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	draw(t_map **map)
{
	(*map)->mlx_ptr = mlx_init();
	(*map)->win_ptr = mlx_new_window((*map)->mlx_ptr , 1000, 700, "FdF");
	(*map)->zoom = 20;
	//draw_lines(map);
	brasenham(10, 400, 100, 150, map);
	mlx_loop((*map)->mlx_ptr);
}

void	draw_lines(t_map **map)
{
	int	x;
	int	y;
	int	z;

	y = 0;
	z = (*map)->zoom;
	while (y < (*map)->height)
	{
		x = 0;
		while (x < (*map)->width)
		{
			//if (x < (*map)->width - 1)
				brasenham(x * z, (x + 1) * z, y * z, y * z, map);
			//if (y < (*map)->height - 1)
				brasenham(x * z, x * z, y * z, (y + 1) * z, map);
			x++;
		}
		y++;
	}
}

void	fill_b(t_bran *b, int x0, int x1, int y0, int y1)
{
	b->dx = ft_abs(x1 - x0);
	b->dy = ft_abs(y1 - y0);
	b->error = 0;
	b->derror = b->dy + 1;
	b->y = y0;
	b->x = x0;
	b->diry = y1 - y0;
	if (b->diry > 0)
		b->diry = 1;
	if (b->diry < 0)
		b->diry = -1;
}

void	brasenham(int x0, int x1, int y0, int y1, t_map **map)
{
	t_bran b;

	fill_b(&b, x0, x1, y0, y1);
	while (b.x <= x1)
	{
		mlx_pixel_put((*map)->mlx_ptr, (*map)->win_ptr, b.x, b.y, 0xEF0909);
		b.error = b.error + b.derror;
		if (b.error >= b.derror + 1)
		{
			b.y = b.y + b.diry;
			b.error = b.error - (b.dx + 1);
		}
		b.x++;
	}	
}