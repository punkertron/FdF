#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_copy;

	lst_copy = *lst;
	if (lst_copy == NULL)
	{
		*lst = new;
		return ;
	}
	while (lst_copy)
	{
		if (lst_copy->next == NULL)
		{
			lst_copy->next = new;
			return ;
		}
		lst_copy = lst_copy->next;
	}
}
