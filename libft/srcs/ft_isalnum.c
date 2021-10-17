#include "libft.h"

int	ft_isalnum(int a)
{
	return (((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
		|| (a >= 48 && a <= 57));
}
