#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*last;

	if (lst)
	{
		ptr = *lst;
		while (ptr != NULL)
		{
			(del)(ptr->content);
			last = ptr->next;
			free(ptr);
			ptr = last;
		}
		*lst = NULL;
	}
}
