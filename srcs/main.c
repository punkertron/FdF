/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:28:09 by drohanne          #+#    #+#             */
/*   Updated: 2021/11/06 02:08:45 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

void	ft_exit(void)
{
	perror("Error");
	exit(1);
}

t_map	*init_map(char *argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		ft_exit();
	get_height_width(&map, argv);
	map->z_max = -2147483648;
	map->z_min = 2147483647;
	return (map);
}

void	get_height_width(t_map **map, char *argv)
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

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit();
	map = init_map(argv);
	i = 0;
	map->cord = malloc(sizeof(int *) * map->height);
	if (map->cord == NULL)
		ft_exit();
	while (get_next_line(fd, &line) > 0)
		map_fill(&line, &map, i++);
	free(line);
	close(fd);
	if (map->width == -1)
	{
		free(map->cord);
		free(map);
		ft_putendl_fd("Empty map!", 2);
		exit(EXIT_FAILURE);
	}
	pre_draw(&map);
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
			exit(EXIT_FAILURE);
		}
		fdf(argv[1]);
	}
	else
		ft_putendl_fd("Bad arguments!", 2);
	return (0);
}
