#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	q;

	q = ft_strlen(s);
	write(fd, s, q);
}
