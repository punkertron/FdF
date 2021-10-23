/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:28:09 by drohanne          #+#    #+#             */
/*   Updated: 2021/10/17 15:28:14 by drohanne         ###   ########.fr       */
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
	char	**split;
	t_map	*map;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit();
	map = init_map();
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_split(line, ' ');
		fill_map(split, map, i);
		i++;
		free_split(split);
	}
	printf("OKAt");
	printf("%d/n", map->cord[0][0]);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("ok");
		fdf(argv[1]);
	}
	else
		ft_putstr_fd("Bad arguments!\n", 2);
	return (0);
}
