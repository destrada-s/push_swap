/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pos_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:54:52 by destrada          #+#    #+#             */
/*   Updated: 2022/12/13 18:37:35 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_add_index_list(t_stack **head, int cmp, int index)
{
	t_stack	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		if (tmp->value == cmp)
			tmp->index = index;
		tmp = tmp->next;
	}
}

t_pos	allocate_index(t_stack **head, t_pos moves, int amount)
{
	int		i;

	i = 0;
	moves.max_index = 0;
	while (i < amount)
	{
		search_add_index_list(head, moves.array[i], i);
		i++;
	}
	moves.max_index = i - 1;
	actualize_pos(head);
	free (moves.array);
	return (moves);
}

int	ft_check_ordered(t_stack **head)
{
	t_stack	*tmp;
	int		flag;
	int		i;

	i = 0;
	tmp = *head;
	flag = 1;
	while (tmp != NULL)
	{
	tmp->actual_pos = i;
		if (tmp->index != i)
			flag = 0;
	i++;
	tmp = tmp->next;
	}
	return (flag);
}

int	adjacent_to_head_b(t_stack *head_a, t_stack *head_b, t_pos *moves)
{
	moves->diff = 0;
	moves->pos2 = 0;
	moves->tmp = head_a;
	moves->neg_flag = 1;
	moves->least_diff = 0;
	if (head_b->index == moves->max_index)
		return (ft_find_lowest(head_a));
	while (head_a != NULL)
	{
		moves->diff = head_a->index - head_b->index;
		if (moves->diff > 0)
			moves->neg_flag = 0;
		if (moves->diff == 1)
			return (head_a->actual_pos);
		else if ((moves->diff > 0 && moves->least_diff > moves->diff)
			|| (moves->least_diff == 0 && moves->diff > 0))
		{
			moves->least_diff = moves->diff;
			moves->pos2 = head_a->actual_pos;
		}
		head_a = head_a -> next;
	}
	if (moves->neg_flag == 1)
		return (ft_find_lowest(moves->tmp));
	return (moves->pos2);
}

int	ft_last_in_list_pos(t_stack *list)
{
	int	i;

	i = 0;
	while (list->next != NULL)
	{
		i++;
		list = list->next;
	}
	return (i);
}
