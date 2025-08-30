/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmezzini <gmezzini@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:56:30 by gmezzini           #+#    #+#            */
/*   Updated: 2022/01/19 12:59:20 by gmezzini          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_list;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst -> content));
	new_list = new;
	lst = lst -> next;
	while (lst != NULL)
	{
		new = ft_lstnew(f(lst -> content));
		if (new == NULL)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		lst = lst -> next;
		ft_lstadd_back(&new_list, new);
	}
	return (new_list);
}
