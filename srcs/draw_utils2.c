/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dunstan <dunstan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 23:42:50 by dunstan           #+#    #+#             */
/*   Updated: 2021/11/03 00:18:37 by dunstan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>

void	my_mlx_pixel_put(t_img *img, int x, int y, int colour)
{
	char	*dst;

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
	if (t->x0 > 1200)
		t->x0 = 1200;
	if (t->x1 > 1200)
		t->x1 = 1200;
	if (t->x0 < 0)
		t->x0 = 0;
	if (t->x1 < 0)
		t->x1 = 0;
	if (t->y0 > 800)
		t->y0 = 800;
	if (t->y1 > 800)
		t->y1 = 800;
	if (t->y0 < 0)
		t->y0 = 0;
	if (t->y1 < 0)
		t->y1 = 0;
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
