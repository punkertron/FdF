#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
	{
		if (str1[a] != str2[a] || str1[a] == '\0'
			|| str2[a] == '\0')
			return ((unsigned char)str1[a] - (unsigned char)str2[a]);
		a++;
	}
	return (0);
}
