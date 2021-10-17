#include "libft.h"

int	ft_isalpha(int a)
{
	return ((a >= 65 && a <= 90) || (a >= 97 && a <= 122));
}
