#include "libft.h"

char	*ft_strrchr(const char *str, int sym)
{
	char	*s;
	char	c;
	int		l;

	s = (char *) str;
	c = (char) sym;
	l = ft_strlen(s);
	while (l >= 0)
	{
		if (s[l] == c)
			return (s + l);
		l--;
	}
	return (NULL);
}
