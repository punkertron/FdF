#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	a;
	unsigned char	f;
	unsigned char	*d;
	unsigned char	*s;

	a = 0;
	f = (unsigned char) c;
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	while (a < n)
	{
		d[a] = s[a];
		if (s[a] == f)
			return (dest + a + 1);
		a++;
	}
	return (NULL);
}
