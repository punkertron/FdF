/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:14:03 by drohanne          #+#    #+#             */
/*   Updated: 2021/11/06 14:57:05 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static void	another_kcode(int kcode, t_map *map)
{
	if (kcode == 122)
	{
		map->angle_z += 15;
		map->flag_rotate = 1;
	}
	else if (kcode == 120)
	{
		map->angle_z -= 15;
		map->flag_rotate = 1;
	}
	else if (kcode == 109)
	{
		map->flag_view = 1;
		map->angle_x = 0;
		map->angle_y = 0;
		map->angle_z = 0;
		map->shift_x = 300;
		map->shift_y = 250;
	}
	return ;
}

static void	other_key(int kcode, t_map *map)
{
	if (kcode == 65451)
	{
		map->zoom += 2;
		if (map->zoom > 200)
			map->zoom = 200;
	}
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
		map->angle_x = 0;
		map->angle_y = 0;
		map->angle_z = 0;
		map->shift_x = 450;
		map->shift_y = 400;
	}
	else if (kcode == 102)
		default_map(&map);
	return ;
}

static void	rotate_map(int kcode, t_map *map)
{
	map->flag_rotate = 1;
	if (kcode == 97)
		map->angle_x += 15;
	else if (kcode == 115)
		map->angle_x -= 15;
	else if (kcode == 113)
		map->angle_y += 15;
	else if (kcode == 119)
		map->angle_y -= 15;
	return ;
}

int	key_hook(int kcode, t_map *map)
{
	if ((kcode >= 65361 && kcode <= 65364) || kcode == 65307
		|| kcode == 109 || kcode == 110 || kcode == 102 || kcode == 65451
		|| kcode == 65453 || kcode == 122 || kcode == 120
		|| kcode == 97 || kcode == 115 || kcode == 113 || kcode == 119)
	{
		if (kcode == 65362)
			map->shift_y -= 40;
		else if (kcode == 65364)
			map->shift_y += 40;
		else if (kcode == 65361)
			map->shift_x -= 40;
		else if (kcode == 65363)
			map->shift_x += 40;
		else if (kcode == 97 || kcode == 115 || kcode == 113 || kcode == 119)
			rotate_map(kcode, map);
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
