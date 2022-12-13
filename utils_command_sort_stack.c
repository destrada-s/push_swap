/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_command_sort_stack.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:54:08 by destrada          #+#    #+#             */
/*   Updated: 2022/12/13 14:24:45 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list_3(t_stack **head)
{
	while (ft_check_lowest_to_highest(head) == 0)
	{
		if (ft_find_biggest(*head) == 0)
			ft_rotate_stack(head, 'a');
		else if (ft_find_biggest(*head) == 1 && ft_find_lowest(*head) == 0)
			ft_swap(head, 'a');
		else if (ft_find_biggest(*head) == 1)
			ft_reverse_rotate_stack(head, 'a');
		else if (ft_find_biggest(*head) == 2)
			ft_swap(head, 'a');
	}
}

void	sort_list_3_inverse(t_stack **head)
{
	while (ft_check_highest_to_lowest(head) == 0)
	{
		if (ft_find_lowest(*head) == 0)
			ft_rotate_stack(head, 'b');
		else if (ft_find_lowest(*head) == 1 && ft_find_biggest(*head) == 0)
			ft_swap(head, 'b');
		else if (ft_find_lowest(*head) == 1)
			ft_reverse_rotate_stack(head, 'b');
		else if (ft_find_lowest(*head) == 2)
			ft_swap(head, 'b');
	}
}

t_pos	ft_index_adjacent_info(t_stack *head)
{
	t_pos	moves;

	moves.amount_of_adjacent_together = 0;
	moves.pos = 0;
	moves.stack_size = ft_last_in_list_pos(head) + 1;
	moves.stack_middle = head->actual_pos
		+ (moves.stack_size - head->actual_pos) / 2;
	while (head->next != NULL)
	{
		if (head->index + 1 != head->next->index)
		{
			if (head->index > head->next->index)
			{
			moves.pos = head->actual_pos;
				return (moves);
			}
		}
		moves.amount_of_adjacent_together++;
		head = head->next;
	}
	return (moves);
}

/*Sort 5*/

void	ft_choose_adjacent_to_send_back(t_stack **head_a,
		t_stack **head_b, t_pos *moves)
{
	while (list_is_empty(*head_b) != 1)
	{
		while (adjacent_to_head_b(*head_a, *head_b, moves) != 0)
		{
			if (adjacent_to_head_b(*head_a, *head_b, moves)
				<= ft_last_in_list_pos(*head_a) / 2)
				ft_rotate_stack(head_a, 'a');
			else
				ft_reverse_rotate_stack(head_a, 'a');
		}
		ft_push(head_b, head_a, 'a');
	}
}

void	sort_list_5(t_stack	**head_a, t_stack **head_b, t_pos moves)
{
	if (ft_check_ordered(head_a) != 1)
	{
		while (ft_last_in_list_pos(*head_a) > 2)
			ft_push(head_a, head_b, 'b');
		sort_list_3(head_a);
		if (list_is_empty(*head_b) == 0)
			sort_list_3_inverse(head_b);
	}
	ft_choose_adjacent_to_send_back(head_a, head_b, &moves);
	while (ft_check_ordered(head_a) != 1)
	{
		moves = ft_index_adjacent_info(*head_a);
		if (moves.pos <= moves.stack_middle)
			ft_rotate_stack(head_a, 'a');
		else if (moves.pos > moves.stack_middle)
			ft_reverse_rotate_stack(head_a, 'a');
	}	
}
