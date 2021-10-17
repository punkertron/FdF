/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:33:05 by drohanne          #+#    #+#             */
/*   Updated: 2021/09/26 13:33:06 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int sym)
{
	char	*s;
	char	c;
	int		l;

	s = (char *) str;
	c = (char) sym;
	l = ft_strlen(s);
	while (l >= 0)
	{
		if (s[l] == c)
			return (s + l);
		l--;
	}
	return (NULL);
}
