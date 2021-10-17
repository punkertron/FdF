#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	l;

	l = 0;
	while (lst)
	{
		l++;
		lst = lst->next;
	}
	return (l);
}
