#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	a;

	a = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == 0)
		return (NULL);
	while (s[start] && a < len)
	{
		dest[a] = s[start];
		a++;
		start++;
	}
	dest[a] = '\0';
	return (dest);
}
