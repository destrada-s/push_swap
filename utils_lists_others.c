/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists_others.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:52:42 by destrada          #+#    #+#             */
/*   Updated: 2022/12/13 09:31:18 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_int_array(int *array, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		ft_printf("%d\n", array[i]);
		i++;
	}
}

int	list_is_empty(t_stack *head)
{
	if (head == NULL)
		return (1);
	return (0);
}

int	ft_find_biggest(t_stack *list)
{
	t_stack	*biggest;

	biggest = list;
	while (list != NULL)
	{
		if (biggest->index < list->index)
			biggest = list;
		list = list->next;
	}
	return (biggest->actual_pos);
}

int	ft_find_lowest(t_stack *list)
{
	t_stack	*lowest;

	lowest = list;
	while (list != NULL)
	{
		if (lowest->index > list->index)
			lowest = list;
		list = list->next;
	}
	return (lowest->actual_pos);
}

int	ft_check_lowest_to_highest(t_stack **head)
{
	t_stack	*tmp;
	int		i;
	int		flag;

	tmp = *head;
	i = 0;
	flag = 1;
	while (tmp->next != NULL)
	{
	tmp->actual_pos = i;
		if (tmp->value > tmp->next->value)
			flag = 0;
		i++;
		tmp = tmp->next;
	}
	tmp->actual_pos = i;
	return (flag);
}
