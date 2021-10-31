/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dunstan <dunstan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:23:36 by dunstan           #+#    #+#             */
/*   Updated: 2021/10/31 23:23:50 by dunstan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

int		get_next_line(int fd, char **line);

char	*ft_strjoin_new(char *s1, char const *s2);
size_t	ft_strlen_new(const char *s);
int		ft_check(char *save, int l);

#endif