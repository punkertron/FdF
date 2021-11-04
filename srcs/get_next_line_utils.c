/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:28:25 by drohanne          #+#    #+#             */
/*   Updated: 2021/11/03 20:22:48 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_new(const char *s)
{
	size_t	i;
	char	*s1;

	s1 = (char *)s;
	i = 0;
	if (!s)
		return (0);
	while (s1[i])
		i++;
	return (i);
}

char	*ft_strjoin_new(char *s1, char const *s2)
{
	char	*dest;
	int		a;
	int		l;

	if (!s1 && !s2)
		return (NULL);
	a = -1;
	l = 0;
	if (!s1)
		s1 = ft_strdup("");
	dest = malloc(sizeof(char) * (ft_strlen_new(s1) + ft_strlen_new(s2) + 1));
	if (dest == 0)
		return (NULL);
	while (s1[++a])
		dest[a] = s1[a];
	while (s2[l])
		dest[a++] = s2[l++];
	dest[a] = '\0';
	free(s1);
	return (dest);
}
