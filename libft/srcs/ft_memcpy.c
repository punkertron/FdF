#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	a;

	a = 0;
	if (!dest && !src)
		return (0);
	while (a < n)
	{
		((unsigned char *)dest)[a] = ((unsigned char *)src)[a];
		a++;
	}
	return (dest);
}
