/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:31:45 by drohanne          #+#    #+#             */
/*   Updated: 2021/09/26 13:31:45 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned int	a;
	unsigned char	*sstr1;
	unsigned char	*sstr2;

	sstr1 = (unsigned char *)str1;
	sstr2 = (unsigned char *)str2;
	a = 0;
	while (a < n)
	{
		if (sstr1[a] != sstr2[a])
			return (sstr1[a] - sstr2[a]);
		a++;
	}
	return (0);
}
