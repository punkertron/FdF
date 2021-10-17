#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	a;
	size_t	count;
	size_t	quantity;
	char	*b;

	b = (char *) big;
	quantity = ft_strlen(little);
	a = 0;
	if (little[0] == '\0')
		return (b);
	while (a < len && b[a] != '\0')
	{
		count = 0;
		while (a + count < len && b[a + count] == little[count]
			&& b[a + count] != '\0' && little[count] != '\0')
		{
			count++;
			if (count == quantity)
				return (b + a);
		}
		a++;
	}
	return (NULL);
}
