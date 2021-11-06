/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sin_cos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 00:51:27 by drohanne          #+#    #+#             */
/*   Updated: 2021/11/06 00:54:28 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

double	cos_deg(int deg)
{
	double	r;

	r = atan(1) * 4;
	r = r * deg / 180;
	return (cos(r));
}

double	sin_deg(int deg)
{
	double	r;

	r = atan(1) * 4;
	r = r * deg / 180;
	return (sin(r));
}
