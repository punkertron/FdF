/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:13:14 by drohanne          #+#    #+#             */
/*   Updated: 2021/11/07 00:51:38 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>

static void	my_mlx_pixel_put(t_img *img, int x, int y, int colour)
{
	char	*dst;

	if (x >= 1200 || x <= 0 || y <= 0 || y >= 800)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

static void	fill_b(t_bran *b, t_cord *t)
{
	b->dx = ft_abs(t->x1 - t->x0);
	b->dy = ft_abs(t->y1 - t->y0);
	b->signx = (t->x0 < t->x1) - 1 * (t->x0 >= t->x1);
	b->signy = (t->y0 < t->y1) - 1 * (t->y0 >= t->y1);
	b->error = b->dx - b->dy;
	b->start_x = t->x0;
	b->start_y = t->y0;
}

static void	add_shift(t_cord *t, t_map **map)
{
	t->x0 += (*map)->shift_x;
	t->x1 += (*map)->shift_x;
	t->y0 += (*map)->shift_y;
	t->y1 += (*map)->shift_y;
}

static void	isometric_more(t_cord *t, t_bran *b, t_map **map)
{
	int	temp1;
	int	temp2;

	b->col0_init = (*map)->col[t->y0][t->x0];
	b->col1_init = (*map)->col[t->y1][t->x1];
	zoom_c(t, *map);
	rotate(&(t->x0), &(t->y0), &(t->z0), map);
	rotate(&(t->x1), &(t->y1), &(t->z1), map);
	if ((*map)->flag_view == 0)
	{
		temp1 = t->x0;
		temp2 = t->y0;
		t->x0 = (temp1 - temp2) * cos((*map)->angle);
		t->y0 = (temp1 + temp2) * sin((*map)->angle) - t->z0;
		temp1 = t->x1;
		temp2 = t->y1;
		t->x1 = (temp1 - temp2) * cos((*map)->angle);
		t->y1 = (temp1 + temp2) * sin((*map)->angle) - t->z1;
	}
	add_shift(t, map);
}

void	brasenham(t_cord c, t_map **map, t_img *img)
{
	t_bran	b;
	t_cord	t;

	t = c;
	isometric_more(&t, &b, map);
	fill_b(&b, &t);
	while (1 == 1)
	{
		my_mlx_pixel_put(img, t.x0, t.y0, ft_color(t, b));
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
