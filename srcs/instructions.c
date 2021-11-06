/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:26:02 by drohanne          #+#    #+#             */
/*   Updated: 2021/11/06 13:33:47 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	put_instructions(t_map **map)
{
	mlx_string_put((*map)->mlx_ptr, (*map)->win_ptr, 1050, 40,
		0x00FFFF, "Welcome to FdF!");
	mlx_string_put((*map)->mlx_ptr, (*map)->win_ptr, 1050, 70,
		0x00FFFF, "shift: arrows");
	mlx_string_put((*map)->mlx_ptr, (*map)->win_ptr, 1050, 85,
		0x00FFFF, "zoom: +/-");
	mlx_string_put((*map)->mlx_ptr, (*map)->win_ptr, 1050, 100,
		0x00FFFF, "rotate Y: q/w");
	mlx_string_put((*map)->mlx_ptr, (*map)->win_ptr, 1050, 115,
		0x00FFFF, "rotate X: a/s");
	mlx_string_put((*map)->mlx_ptr, (*map)->win_ptr, 1050, 130,
		0x00FFFF, "rotate Z: z/x");
	mlx_string_put((*map)->mlx_ptr, (*map)->win_ptr, 1050, 145,
		0x00FFFF, "top view: m");
	mlx_string_put((*map)->mlx_ptr, (*map)->win_ptr, 1050, 160,
		0x00FFFF, "side view: n");
	mlx_string_put((*map)->mlx_ptr, (*map)->win_ptr, 1050, 175,
		0x00FFFF, "default: f");
}
