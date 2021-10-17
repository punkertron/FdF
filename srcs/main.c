#include "fdf.h"

void	ft_exit(void)
{
	perror("Error");
	exit(1);
}


void	fdf(char *argv)
{
	int		fd;
	char	*line;
	char	**split;
	t_map	*map;

	fd = open(ft_itoa(argv), O_RDONLY);
	if (fd == -1)
		ft_perror();
	map = init_map();
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_split(line, ' ');
		fill_map(split, map);
		free_split(split);
	}
	
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fdf(argv[1]);
	else
		ft_putstr_fd("Bad arguments!\n", 2);
	return (0);
}
