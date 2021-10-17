/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:32:32 by drohanne          #+#    #+#             */
/*   Updated: 2021/09/26 13:32:33 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		a;
	int		l;

	if (!s1 || !s2)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == 0)
		return (NULL);
	l = 0;
	a = 0;
	while (s1[a])
	{
		dest[a] = s1[a];
		a++;
	}
	while (s2[l])
	{
		dest[a] = s2[l];
		a++;
		l++;
	}
	dest[a] = '\0';
	return (dest);
}
