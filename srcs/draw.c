/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dunstan <dunstan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:53:34 by drohanne          #+#    #+#             */
/*   Updated: 2021/11/03 00:31:34 by dunstan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static void	draw(t_map **map)
{
	t_img	img;

	img.img = mlx_new_image((*map)->mlx_ptr, 1200, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	(*map)->img = img.img;
	draw_lines(map, &img);
	mlx_put_image_to_window((*map)->mlx_ptr, (*map)->win_ptr, img.img, 0, 0);
}

/*
65361 - 65364 (arrows) - moving the map;
111 and 108 (O and L) - angle
*/

static int	key_hook(int keycode, t_map *map)
{
	if ((keycode >= 65361 && keycode <= 65364) || keycode == 65307
		|| keycode == 108 || keycode == 111 || keycode == 102)
	{
		if (keycode == 65362)
			map->shift_y -= 25;
		else if (keycode == 65364)
			map->shift_y += 25;
		else if (keycode == 65361)
			map->shift_x -= 20;
		else if (keycode == 65363)
			map->shift_x += 20;
		else if (keycode == 111)
			map->angle += 0.1;
		else if (keycode == 108)
			map->angle -= 0.1;
		else if (keycode == 65307)
			esc_exit(map);
		else if (keycode == 102)
			default_map(&map);
		mlx_destroy_image(map->mlx_ptr, map->img);
		draw(&map);
	}
	printf("%d\n", keycode);
	return (1);
}

void	pre_draw(t_map **map)
{
	(*map)->zoom = find_zoom(map);
	(*map)->mlx_ptr = mlx_init();
	(*map)->win_ptr = mlx_new_window((*map)->mlx_ptr, 1200, 800, "FdF");
	draw(map);
	mlx_key_hook((*map)->win_ptr, key_hook, *map);
	mlx_loop((*map)->mlx_ptr);
}

void	draw_lines(t_map **map, t_img *img)
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
				brasenham(zoom_c(c, (*map)->zoom), map, img);
			}
			c.x1 = c.x0;
			if (c.y0 < (*map)->height - 1)
			{
				c.y1 += 1;
				brasenham(zoom_c(c, (*map)->zoom), map, img);
			}
			c.x0++;
		}
		c.y0++;
	}
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
