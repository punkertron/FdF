/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:33:00 by drohanne          #+#    #+#             */
/*   Updated: 2021/09/26 13:33:01 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	a;
	size_t	count;
	size_t	quantity;
	char	*b;

	b = (char *) big;
	quantity = ft_strlen(little);
	a = 0;
	if (little[0] == '\0')
		return (b);
	while (a < len && b[a] != '\0')
	{
		count = 0;
		while (a + count < len && b[a + count] == little[count]
			&& b[a + count] != '\0' && little[count] != '\0')
		{
			count++;
			if (count == quantity)
				return (b + a);
		}
		a++;
	}
	return (NULL);
}
