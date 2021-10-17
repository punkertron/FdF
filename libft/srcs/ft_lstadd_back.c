/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:30:54 by drohanne          #+#    #+#             */
/*   Updated: 2021/09/26 13:30:56 by drohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
