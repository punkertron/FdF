#include <string.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned int	a;
	unsigned char	*sstr1;
	unsigned char	*sstr2;

	sstr1 = (unsigned char *)str1;
	sstr2 = (unsigned char *)str2;
	a = 0;
	while (a < n)
	{
		if (sstr1[a] != sstr2[a])
			return (sstr1[a] - sstr2[a]);
		a++;
	}
	return (0);
}
