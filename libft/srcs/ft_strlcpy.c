/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:32:41 by drohanne          #+#    #+#             */
/*   Updated: 2021/09/26 13:32:42 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	l;
	size_t	q;

	l = 0;
	q = ft_strlen(src);
	if (!src)
	{
		return (0);
	}
	if (size == 0)
	{
		return (q);
	}
	while (src[l] != '\0' && l < size - 1)
	{
		dst[l] = src[l];
		l++;
	}
	dst[l] = '\0';
	return (q);
}
