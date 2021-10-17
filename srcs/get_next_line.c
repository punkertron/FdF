/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:28:21 by drohanne          #+#    #+#             */
/*   Updated: 2021/10/17 15:28:22 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	ft_check_newline(char *s)
{
	int	a;

	a = 0;
	if (!s)
		return (-1);
	while (s[a])
	{
		if (s[a] == '\n')
			return (a);
		a++;
	}
	return (-1);
}

static	int	ft_fill(char **save, char **line)
{
	char	*tmp;
	int		a;
	int		pos;
	int		q;

	q = ft_strlen_new(*save);
	pos = ft_check_newline(*save);
	if (pos != -1)
		q = pos;
	tmp = malloc(sizeof(char) * (q + 1));
	if (tmp == NULL)
		return (0);
	a = 0;
	while ((*save)[a] && (*save)[a] != '\n')
	{
		tmp[a] = (*save)[a];
		a++;
	}
	tmp[a] = '\0';
	*line = tmp;
	return (1);
}

static	char	*ft_trim(char **save)
{
	int		pos;
	int		a;
	char	*tmp;

	if (!(*save))
		return (0);
	pos = ft_check_newline(*save);
	if (pos == -1)
		pos = ft_strlen_new(*save);
	if (!(*save)[pos])
	{
		free(*save);
		return (0);
	}
	tmp = malloc(sizeof(char) * (ft_strlen_new(*save) + 1 - pos));
	if (!tmp)
		return (0);
	a = 0;
	pos++;
	while ((*save)[pos])
		tmp[a++] = (*save)[pos++];
	tmp[a] = '\0';
	free(*save);
	return (tmp);
}

static	int	ft_result(char **save, char **line, char **buf, int ret)
{
	free(*buf);
	if (!ft_fill(save, line))
		return (-1);
	*save = ft_trim(save);
	if (ret == 0)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buf;
	int			ret;

	if ((BUFFER_SIZE <= 0) || !line || read(fd, 0, 0) == -1 || fd > 4095)
		return (-1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	ret = 1;
	while (ret && ft_check_newline(save) == -1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (-1);
		}
		buf[ret] = '\0';
		save = ft_strjoin_new(save, buf);
	}
	return (ft_result(&save, line, &buf, ret));
}
