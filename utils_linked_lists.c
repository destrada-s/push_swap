/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_linked_lists.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:19:31 by destrada          #+#    #+#             */
/*   Updated: 2022/12/09 08:57:38 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_stack *list)
{
	while (list != NULL)
	{
		ft_printf("%d\n", list->value);
		list = list->next;
	}
}

void	ft_print_list_data(t_stack *list)
{
	while (list != NULL)
	{
		ft_printf("Value: %d; Pos: %d , Final index:%d\n",
			list->value, list->actual_pos, list->index);
		list = list->next;
	}
}

void	ft_print_list_both_stacks_data(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("STACK INFORMATION:\n");
	while (stack_a != NULL || stack_b != NULL)
	{
		if (list_is_empty(stack_a) != 1)
		{
			ft_printf("Value: %d; Pos: %d , Final index:%d		|",
				stack_a->value, stack_a->actual_pos, stack_a->index);
			stack_a = stack_a->next;
		}
		else
			ft_printf("                                   		|");
		if (list_is_empty(stack_b) != 1)
		{
			ft_printf("Value: %d; Pos: %d , Final index:%d",
				stack_b->value, stack_b->actual_pos, stack_b->index);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
}

t_stack	*ft_last_in_list(t_stack *list)
{
	while (list->next != NULL)
	{
		list = list->next;
	}
	return (list);
}

t_stack	*ft_2nlast_in_list(t_stack *list)
{
	while (list->next->next != NULL)
	{
		list = list->next;
	}
	return (list);
}

t_stack	*ft_go_to_in_list(t_stack *list, int pos)
{
	while (list->actual_pos != pos)
	{
		list = list -> next;
	}
	return (list);
}

t_stack	*ft_nlast_in_list(t_stack *list)
{
	while (list->next->next->next != NULL)
	{
		list = list->next;
	}
	return (list);
}