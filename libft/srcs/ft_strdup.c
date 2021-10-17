#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		a;
	char	*dest;

	dest = malloc(ft_strlen(src) + 1);
	if (dest == 0)
		return (NULL);
	a = 0;
	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}
