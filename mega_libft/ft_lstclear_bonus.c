/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:50:12 by destrada          #+#    #+#             */
/*   Updated: 2022/10/04 15:24:50 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*header;
	t_list	*nextdel;

	header = *lst;
	while (header)
	{
		nextdel = header -> next;
		del(header -> content);
		free(header);
		header = nextdel;
	}
	*lst = NULL;
}
