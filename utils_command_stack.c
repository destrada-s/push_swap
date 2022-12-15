/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_command_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:17:54 by destrada          #+#    #+#             */
/*   Updated: 2022/12/15 19:43:09 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_insert_in_stack(t_stack **head, int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)(ft_calloc(sizeof(t_stack), 1));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->actual_pos = 0;
	new_node->next = *head;
	*head = new_node;
	return (*head);
}

void	actualize_pos(t_stack **head_a)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *head_a;
	while (tmp != NULL)
	{
		tmp->actual_pos = i;
		i++;
		tmp = tmp ->next;
	}
}

void	ft_rotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*head))
		return ;
	tmp = (*head)->next;
	last = ft_last_in_list(*head);
	last->next = *head;
	last = last->next;
	last->next = NULL;
	*head = tmp;
}

void	ft_reverse_rotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*nd2tolast;

	if (!(*head))
		return ;
	nd2tolast = ft_2nlast_in_list(*head);
	tmp = ft_last_in_list(*head);
	tmp->next = *head;
	*(head) = tmp;
	nd2tolast ->next = NULL;
}

void	ft_swap(t_stack **head, char stack)
{
	t_stack	*tmp;

	tmp = *head;
	tmp = tmp->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
	actualize_pos(head);
	ft_printf("s%c\n", stack);
}
