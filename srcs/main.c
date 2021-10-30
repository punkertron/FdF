/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dunstan <dunstan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:28:09 by drohanne          #+#    #+#             */
/*   Updated: 2021/10/30 19:26:53 by dunstan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

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
	close(fd);
	draw(&map);
	free_map(&map);
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], __O_DIRECTORY);
		if (fd > 0)
		{
			close(fd);
			ft_putendl_fd("Directory, not a file!", 2);
			exit(-1);
		}
		fdf(argv[1]);
	}
	else
		ft_putstr_fd("Bad arguments!\n", 2);
	return (0);
}
