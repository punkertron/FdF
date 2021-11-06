/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:53:34 by drohanne          #+#    #+#             */
/*   Updated: 2021/11/06 14:41:48 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static void	draw_lines(t_map **map, t_img *img)
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
				brasenham(c, map, img);
			}
			c.x1 = c.x0;
			if (c.y0 < (*map)->height - 1)
			{
				c.y1 += 1;
				brasenham(c, map, img);
			}
			c.x0++;
		}
		c.y0++;
	}
}

void	draw(t_map **map)
{
	t_img	img;

	img.img = mlx_new_image((*map)->mlx_ptr, 1200, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	(*map)->img = img.img;
	draw_lines(map, &img);
	mlx_put_image_to_window((*map)->mlx_ptr, (*map)->win_ptr, img.img, 0, 0);
	put_instructions(map);
}

void	pre_draw(t_map **map)
{
	(*map)->mlx_ptr = mlx_init();
	(*map)->win_ptr = mlx_new_window((*map)->mlx_ptr, 1200, 800, "FdF");
	default_map(map);
	fill_col(map);
	draw(map);
	mlx_key_hook((*map)->win_ptr, key_hook, *map);
	mlx_loop((*map)->mlx_ptr);
}
