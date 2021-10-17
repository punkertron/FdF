#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*first;

	ptr = ft_lstnew((*f)(lst->content));
	if (ptr == 0)
		return (NULL);
	first = ptr;
	lst = lst->next;
	while (lst != NULL)
	{
		ptr->next = ft_lstnew((*f)(lst->content));
		if (ptr->next == NULL)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		ptr = ptr->next;
		lst = lst->next;
	}
	ptr->next = NULL;
	return (first);
}
