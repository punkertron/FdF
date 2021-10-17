#include "libft.h"

static	int	ft_check_sym(char c)
{
	if (c == '\t' || c == '\n' || c == ' '
		|| c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

static	int	ft_check_size(const char *s)
{
	int	size;

	size = 0;
	while (*s >= '0' && *s <= '9')
	{
		s++;
		size++;
		if (size == 19)
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *s)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (ft_check_sym(s[i]) == 1)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg = -1;
		i++;
	}
	if (ft_check_size(s + i) != 0)
	{
		if (neg == -1)
			return (0);
		return (-1);
	}
	while (s[i] >= '0' && s[i] <= '9')
		res = 10 * res + s[i++] - '0';
	return (res * neg);
}
