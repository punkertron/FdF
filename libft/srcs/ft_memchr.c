#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t n)
{
	unsigned char	*buf2;
	unsigned char	f;
	size_t			a;

	buf2 = (unsigned char *) buf;
	a = 0;
	f = (unsigned char) c;
	while (a < n)
	{
		if (buf2[a] == f)
			return ((void *)(buf + a));
		a++;
	}
	return (NULL);
}
