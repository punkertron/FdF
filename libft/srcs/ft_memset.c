#include "libft.h"

void	*ft_memset(void *dest, int val, size_t n)
{
	unsigned char	*str;
	unsigned char	t;
	size_t			a;

	str = (unsigned char *) dest;
	t = (unsigned char) val;
	a = 0;
	while (a < n)
	{
		str[a] = t;
		a++;
	}
	return (dest);
}
