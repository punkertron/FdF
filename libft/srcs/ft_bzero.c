#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	q;

	q = 0;
	while (q < n)
	{
		((unsigned char *)s)[q] = '\0';
		q++;
	}
}
