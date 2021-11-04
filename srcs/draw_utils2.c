/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:13:14 by drohanne          #+#    #+#             */
/*   Updated: 2021/11/04 16:13:17 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>

void	my_mlx_pixel_put(t_img *img, int x, int y, int colour)
{
	char	*dst;

	if (x > 1200)
		x = 1200;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (y > 800)
		y = 800;
	if (x == 0 || x == 1200 || y == 0 || y == 800)
		colour = (0);
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

void	fill_b(t_bran *b, t_cord *t)
{
	b->dx = ft_abs(t->x1 - t->x0);
	b->dy = ft_abs(t->y1 - t->y0);
	b->signx = (t->x0 < t->x1) - 1 * (t->x0 >= t->x1);
	b->signy = (t->y0 < t->y1) - 1 * (t->y0 >= t->y1);
	b->error = b->dx - b->dy;
}

void	add_shift(t_cord *t, t_map **map)
{
	t->x0 += (*map)->shift_x;
	t->x1 += (*map)->shift_x;
	t->y0 += (*map)->shift_y;
	t->y1 += (*map)->shift_y;
}

void	isometric(t_cord *t, t_map **map)
{
	int	z;
	int	z1;
	int	temp1;
	int	temp2;

	z = (*map)->cord[t->y0 / (*map)->zoom][t->x0 / (*map)->zoom];
	z1 = (*map)->cord[t->y1 / (*map)->zoom][t->x1 / (*map)->zoom];
	temp1 = t->x0;
	temp2 = t->y0;
	t->x0 = (temp1 - temp2) * cos((*map)->angle);
	t->y0 = (temp1 + temp2) * sin((*map)->angle) - z;
	temp1 = t->x1;
	temp2 = t->y1;
	t->x1 = (temp1 - temp2) * cos((*map)->angle);
	t->y1 = (temp1 + temp2) * sin((*map)->angle) - z1;
	if (z == 0)
		z = z1;
	add_shift(t, map);
	(*map)->colour = ft_colour(z);
}

void	brasenham(t_cord c, t_map **map, t_img *img)
{
	t_bran	b;
	t_cord	t;

	t = c;
	isometric(&t, map);
	fill_b(&b, &t);
	while (1 == 1)
	{
		my_mlx_pixel_put(img, t.x0, t.y0, (*map)->colour);
		if (t.x0 == t.x1 || t.y0 == t.y1)
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
