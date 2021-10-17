#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*res;

	res = malloc(num * size);
	if (res == 0)
		return (NULL);
	ft_bzero(res, num * size);
	return (res);
}
