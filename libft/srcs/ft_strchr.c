#include "libft.h"

char	*ft_strchr(const char *str, int sym)
{
	char	*s;
	char	c;
	int		a;

	s = (char *) str;
	c = (char) sym;
	a = 0;
	while (s[a])
	{
		if (s[a] == c)
			return (s + a);
		a++;
	}
	if (s[a] == c)
		return (s + a);
	return (NULL);
}
