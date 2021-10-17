/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:32:37 by drohanne          #+#    #+#             */
/*   Updated: 2021/09/26 13:32:38 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l;
	size_t	q;
	size_t	k;
	size_t	k1;

	l = 0;
	q = ft_strlen(src);
	k = ft_strlen(dst);
	k1 = k;
	if (size <= k)
		return (q + size);
	while (src[l] != '\0' && (l + k1) < size - 1)
	{
		dst[k] = src[l];
		k++;
		l++;
	}
	dst[k] = '\0';
	return (q + k - l);
}
