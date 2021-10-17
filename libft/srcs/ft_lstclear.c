/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:31:04 by drohanne          #+#    #+#             */
/*   Updated: 2021/09/26 13:31:05 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
