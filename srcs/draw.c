/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:53:34 by drohanne          #+#    #+#             */
/*   Updated: 2021/11/06 02:11:48 by drohanne         ###   ########.fr       */
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

static void	draw(t_map **map)
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

static void	other_key(int kcode, t_map *map)
{
	if (kcode == 65451)
		map->zoom += 2;
	else if (kcode == 65453 && map->zoom > 1)
	{
		map->zoom -= 2;
		if (map->zoom < 1)
			map->zoom = 1;
	}
	else if (kcode == 110)
	{
		map->flag_view = 0;
		map->angle = 0;
		map->shift_x = 450;
		map->shift_y = 400;
	}
	else if (kcode == 102)
		default_map(&map);
	return ;
}

static int	key_hook(int kcode, t_map *map)
{
	if ((kcode >= 65361 && kcode <= 65364) || kcode == 65307
		|| kcode == 109 || kcode == 110 || kcode == 102 || kcode == 65451
		|| kcode == 65453 || kcode == 122 || kcode == 120)
	{
		if (kcode == 65362)
			map->shift_y -= 20;
		else if (kcode == 65364)
			map->shift_y += 20;
		else if (kcode == 65361)
			map->shift_x -= 20;
		else if (kcode == 65363)
			map->shift_x += 20;
		else if (kcode == 65307)
			esc_exit(map);
		else if (kcode == 122 || kcode == 109 || kcode == 120)
			another_kcode(kcode, map);
		else
			other_key(kcode, map);
		mlx_destroy_image(map->mlx_ptr, map->img);
		draw(&map);
	}
	return (1);
}

void	pre_draw(t_map **map)
{
	(*map)->mlx_ptr = mlx_init();
	(*map)->win_ptr = mlx_new_window((*map)->mlx_ptr, 1200, 800, "FdF");
	default_map(map);
	draw(map);
	mlx_key_hook((*map)->win_ptr, key_hook, *map);
	mlx_loop((*map)->mlx_ptr);
}
