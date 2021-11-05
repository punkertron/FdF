/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:53:34 by drohanne          #+#    #+#             */
/*   Updated: 2021/11/05 23:22:42 by drohanne         ###   ########.fr       */
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
	else if (kcode == 102)
		default_map(&map);
	return ;
}

static int	key_hook(int kcode, t_map *map)
{
	if ((kcode >= 65361 && kcode <= 65364) || kcode == 65307 || 
	(kcode >= 108 && kcode <= 111) || kcode == 102 || kcode == 65451 || kcode == 65453 ||
	kcode == 122 || kcode == 120)
	{
		if (kcode == 65362)
			map->shift_y -= 25;
		else if (kcode == 65364)
			map->shift_y += 25;
		else if (kcode == 65361)
			map->shift_x -= 20;
		else if (kcode == 65363)
			map->shift_x += 20;
		else if (kcode == 111)
			map->angle += 2; //сделать обратно. если 2.5, то 0.5. Если 0.5, то 2.5
		else if (kcode == 108)
		{
			fprintf(stderr, "%f\n", map->angle );
			map->angle -= 0.1;
		}
		else if (kcode == 65307)
			esc_exit(map);
		else if (kcode == 122)
		{
			map->angle_x += 15;
			//map->angle_y += 15;
			//map->angle_z += 15;
			map->flag_rotate = 1;
		}
		else if (kcode == 109)
		{
			map->flag_view = 1;
			map->angle_x = 0;
			map->angle_y = 0;
			map->angle_z = 0;
		}
		else if (kcode == 110) //вид сбоку (N)
		{
			map->flag_view = 0;
			map->angle = 0;
		}
		/*
		else if (kcode == 109) //вид сбоку (m)
		{
			map->flag_rotate = 1;
			map->angle_x = -90;
			map->angle_y = 90;
			map->angle_z = 0;
		}
		*/
		else
			other_key(kcode, map);
		mlx_destroy_image(map->mlx_ptr, map->img);
		draw(&map);
	}
	fprintf(stderr, "%d\n", kcode);
	return (1);
}

void	pre_draw(t_map **map)
{
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
