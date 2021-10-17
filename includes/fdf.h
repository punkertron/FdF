#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>

# include "../libft/includes/libft.h"
# include "get_next_line.h"

typedef struct s_map
{
	int		x;
	int		y;
	int		z;
	s_map	*next;
	s_map	*prev;
} t_map;

void	fdf(char *argv);
void	ft_exit(void);

#endif