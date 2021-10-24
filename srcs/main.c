/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:28:09 by drohanne          #+#    #+#             */
/*   Updated: 2021/10/24 19:06:39 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit(void)
{
	perror("Error");
	exit(1);
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
	map = init_map();
	i = 0;
	map->cord = malloc(sizeof(map->cord));
	if (map->cord == NULL)
		ft_exit();
	while (get_next_line(fd, &line) > 0)
		map_fill(&line, map, i++);
	map_fill(&line, map, i);
	close(fd);
	for (int i = 0; i < 2; i++)
	{
		for (int a = 0; a < 12; a++)
		{
			printf("%d ", map->cord[i][a]);
		}
		printf("\n");
	}
	sleep(1000);
	//free_map(&map);
}

void	map_fill(char **line, t_map *map, int i)
{
	char **split;

	split = ft_split(*line, ' ');
	if (split[0] == NULL)
		exit(1);
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
