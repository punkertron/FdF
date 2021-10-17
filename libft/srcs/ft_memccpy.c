/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:31:37 by drohanne          #+#    #+#             */
/*   Updated: 2021/09/26 13:31:38 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	a;
	unsigned char	f;
	unsigned char	*d;
	unsigned char	*s;

	a = 0;
	f = (unsigned char) c;
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	while (a < n)
	{
		d[a] = s[a];
		if (s[a] == f)
			return (dest + a + 1);
		a++;
	}
	return (NULL);
}
