/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dunstan <dunstan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:53:34 by drohanne          #+#    #+#             */
/*   Updated: 2021/10/31 23:21:48 by dunstan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>

void	draw(t_map **map)
{
	(*map)->zoom = find_zoom(map);
	(*map)->mlx_ptr = mlx_init();
	(*map)->win_ptr = mlx_new_window((*map)->mlx_ptr, 1200, 700, "FdF");
	draw_lines(map);
	mlx_loop((*map)->mlx_ptr);
}

void	draw_lines(t_map **map)
{
	t_cord	c;

	c.y0 = 0;
	while (c.y0 < (*map)->height)
	{
		c.x0 = 0;
		while (c.x0 < (*map)->width)
		{
			c.y1 = c.y0;
			c.x1 = c.x0;
			if (c.x0 < (*map)->width - 1)
			{
				c.x1 += 1;
				brasenham(zoom_c(c, (*map)->zoom), map);
			}
			c.x1 = c.x0;
			if (c.y0 < (*map)->height - 1)
			{
				c.y1 += 1;
				brasenham(zoom_c(c, (*map)->zoom), map);
			}
			c.x0++;
		}
		c.y0++;
	}
}

static void	fill_b(t_bran *b, t_cord *t)
{
	b->dx = ft_abs(t->x1 - t->x0);
	b->dy = ft_abs(t->y1 - t->y0);
	b->signx = (t->x0 < t->x1) - 1 * (t->x0 >= t->x1);
	b->signy = (t->y0 < t->y1) - 1 * (t->y0 >= t->y1);
	b->error = b->dx - b->dy;
	t->x0 += 500;
	t->x1 += 500;
	t->y0 += 150;
	t->y1 += 150;
}

static void	isometric(t_cord *t, t_map **map)
{
	int	z;
	int	z1;
	int	temp1;
	int	temp2;

	z = (*map)->cord[t->y0 / (*map)->zoom][t->x0 / (*map)->zoom];
	z1 = (*map)->cord[t->y1 / (*map)->zoom][t->x1 / (*map)->zoom];
	temp1 = t->x0;
	temp2 = t->y0;
	t->x0 = (temp1 - temp2) * cos(0.523599);
	t->y0 = (temp1 + temp2) * sin(0.523599) - z;
	temp1 = t->x1;
	temp2 = t->y1;
	t->x1 = (temp1 - temp2) * cos(0.523599);
	t->y1 = (temp1 + temp2) * sin(0.523599) - z1;
	if (z == 0)
		z = z1;
	(*map)->colour = ft_colour(z);
}

void	brasenham(t_cord c, t_map **map)
{
	t_bran	b;
	t_cord	t;

	t = c;
	isometric(&t, map);
	fill_b(&b, &t);
	while (1 == 1)
	{
		mlx_pixel_put((*map)->mlx_ptr, (*map)->win_ptr, t.x0, t.y0,
			(*map)->colour);
		if (t.x0 == t.x1 && t.y0 == t.y1)
			break ;
		b.error2 = b.error * 2;
		if (b.error2 > -b.dy)
		{
			b.error -= b.dy;
			t.x0 += b.signx;
		}
		if (b.error2 < b.dx)
		{
			b.error += b.dx;
			t.y0 += b.signy;
		}
	}
}
