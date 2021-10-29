/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dunstan <dunstan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:28:09 by drohanne          #+#    #+#             */
/*   Updated: 2021/10/29 23:38:40 by dunstan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit(void)
{
	perror("Error");
	exit(1);
}

void	get_heght_width(t_map **map, char *argv)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit();
	(*map)->width = -1;
	(*map)->height = 0;
	while (get_next_line(fd, &line))
	{
		free(line);
		(*map)->height++;
	}
	free(line);
	close(fd);
}

void	fdf(char *argv)
{
	int		fd;
	int		i;
	char	*line;
	t_map	*map;

	map = init_map(argv);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit();
	i = 0;
	map->cord = malloc(sizeof(int *) * map->height);
	if (map->cord == NULL)
		ft_exit();
	while (get_next_line(fd, &line) > 0)
		map_fill(&line, &map, i++);
	free(line);
	//map_fill(&line, &map, i);
	close(fd);
	free_map(&map);
}

void	map_fill(char **line, t_map **map, int i)
{
	char	**split;
	int		a;

	a = 0;
	split = ft_split(*line, ' ');
	if (split[0] == NULL)
		exit(1);
	if ((*map)->width == -1)
	{
		while (split[a])
			a++;
		(*map)->width = a;
	}
	fill_map(split, map, i);
	free_split(split);
	free(*line);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fdf(argv[1]);
	else
		ft_putstr_fd("Bad arguments!\n", 2);
	return (0);
}
