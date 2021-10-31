/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dunstan <dunstan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 00:22:05 by dunstan           #+#    #+#             */
/*   Updated: 2021/10/31 22:55:03 by dunstan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int a)
{
	if (a >= 0)
		return (a);
	return (-a);
}

int	ft_colour(int i)
{
	if (i == 0)
		return (0xFFFFFF);
	if (i < 50)
		return (i * 120000);
	else if (i < 200)
		return (10000 + i * 10000);
	else
		return (i);
}

t_cord	zoom_c(t_cord c, int z)
{
	t_cord	r;

	r = c;
	r.x0 *= z;
	r.x1 *= z;
	r.y0 *= z;
	r.y1 *= z;
	return (r);
}

int	find_zoom(t_map **map)
{
	fprintf(stderr, "width = %d\n", (*map)->width);
	fprintf(stderr, "height = %d\n", (*map)->height);
	(void) map;
	return (40);
}
