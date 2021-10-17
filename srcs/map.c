#include "fdf.h"

t_map	*init_map(void)
{
	t_map	*map;

	t_map = malloc(sizeof(t_map));
	if (t_map == NULL)
		ft_exit();
	map->next = NULL;
	map->prev = NULL;
	map->x = -1;
	map->y = -1;
	map->z = 0;
}

void	free_split(char **split)
{
	int	a;

	a = 0;
	while (split[a])
	{
		free(split[a]);
		a++;
	}
	free(split[a]);
	free(split);
}

void	fill_map(char **split, t_map *map)
{
	int	a;
	int	max_x;
	int	max_y;

	a = 0;
	max_y = max_y(map);
	max_x = max_x(map);
	while (split[a])
	{
		map->z = ft_itoa(split[a]);
	}
}
