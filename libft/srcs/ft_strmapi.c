#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	a;
	char			*dest;

	a = 0;
	if (!s)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dest == 0)
		return (NULL);
	while (s[a] != '\0')
	{
		dest[a] = (*f)(a, s[a]);
		a++;
	}
	dest[a] = '\0';
	return (dest);
}
