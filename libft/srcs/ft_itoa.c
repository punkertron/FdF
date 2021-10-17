#include "libft.h"

static	int	ft_count(int n)
{
	int				count;
	long long int	l;

	l = (long long int) n;
	count = 0;
	if (n <= 0)
	{
		count++;
		l = -l;
	}
	while (l != 0)
	{
		count++;
		l = l / 10;
	}
	return (count);
}

static	void	ft_reverse(char *s)
{
	int		a;
	int		l;
	char	c;

	l = ft_strlen(s);
	a = -1;
	while (++a < --l)
	{
		c = s[a];
		s[a] = s[l];
		s[l] = c;
	}
}

static	void	ft_end(char *s, int n)
{
	int	l;

	l = ft_strlen(s);
	if (n < 0)
	{
		s[l] = '-';
		s[l + 1] = '\0';
	}
}

char	*ft_itoa(int n)
{
	int				a;
	char			*s;
	long long int	q;

	s = malloc(sizeof(char) * (ft_count(n) + 1));
	if (s == 0)
		return (NULL);
	q = n;
	if (q < 0)
		q = -q;
	a = 0;
	s[a] = q % 10 + '0';
	q = q / 10;
	while (q)
	{
		s[++a] = q % 10 + '0';
		q = q / 10;
	}
	s[a + 1] = '\0';
	ft_end(s, n);
	ft_reverse(s);
	return (s);
}
