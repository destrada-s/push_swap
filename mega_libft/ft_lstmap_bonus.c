/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:38:48 by destrada          #+#    #+#             */
/*   Updated: 2022/10/05 11:44:08 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*iterated_list;
	t_list	*new;

	iterated_list = NULL;
	if (!lst && !f)
		return (NULL);
	while (lst)
	{
		new = ft_lstnew(0);
		if (!new)
		{
			ft_lstclear(&iterated_list, del);
			return (0);
		}
		new -> content = f(lst -> content);
		ft_lstadd_back(&iterated_list, new);
		lst = lst -> next;
	}
	return (iterated_list);
}
