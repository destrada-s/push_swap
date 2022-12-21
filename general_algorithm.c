/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:46:59 by destrada          #+#    #+#             */
/*   Updated: 2022/12/19 20:26:34 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_best_move_condition_1(t_stack **head_a,
		t_stack **head_b, t_pos *moves)
{
	if (moves->best_in_b_closer_last == 1
		&& moves->send_is_closer_last == 1)
	{
		while (moves->best_in_b != 0 && moves->send_to_b_pos != 0)
		{
			ft_rrr(head_a, head_b);
			moves->best_in_b--;
			moves->send_to_b_pos--;
		}
		while (moves->best_in_b != 0)
		{
			ft_reverse_rotate_stack(head_b, 'b');
			moves->best_in_b--;
		}
		while (moves->send_to_b_pos != 0)
		{
			ft_reverse_rotate_stack(head_a, 'a');
			moves->send_to_b_pos--;
		}
	}
}

static	void	ft_best_move_condition_2(t_stack **head_a,
		t_stack **head_b, t_pos *moves)
{
	if (moves->best_in_b_closer_last == 0
		&& moves->send_is_closer_last == 0)
	{
		while (moves->best_in_b != 0 && moves->send_to_b_pos != 0)
		{
			ft_rr(head_a, head_b);
			moves->best_in_b--;
			moves->send_to_b_pos--;
		}
		while (moves->best_in_b != 0)
		{
			ft_rotate_stack(head_b, 'b');
			moves->best_in_b--;
		}
		while (moves->send_to_b_pos != 0)
		{
			ft_rotate_stack(head_a, 'a');
			moves->send_to_b_pos--;
		}
	}
}

static	void	ft_best_move_condition_3(t_stack **head_a,
		t_stack **head_b, t_pos *moves)
{
	if (moves->best_in_b_closer_last == 0
		&& moves->send_is_closer_last == 1)
	{
		while (moves->best_in_b != 0)
		{
			ft_rotate_stack(head_b, 'b');
			moves->best_in_b--;
		}
		while (moves->send_to_b_pos != 0)
		{
			ft_reverse_rotate_stack(head_a, 'a');
			moves->send_to_b_pos--;
		}
	}
}

static	void	ft_best_move_condition_4(t_stack **head_a,
		t_stack **head_b, t_pos *moves)
{
	if (moves->best_in_b_closer_last == 1
		&& moves->send_is_closer_last == 0)
	{
		while (moves->best_in_b != 0)
		{
			ft_reverse_rotate_stack(head_b, 'b');
			moves->best_in_b--;
		}
		while (moves->send_to_b_pos != 0)
		{
			ft_rotate_stack(head_a, 'a');
			moves->send_to_b_pos--;
		}
	}
}

void	sort_list_general_2(t_stack	**head_a, t_stack **head_b, t_pos moves)
{
	ft_send_higher_to_lower(head_a, head_b, &moves);
	while (list_is_empty(*head_b) != 1)
	{
		ft_best_solution_back(*head_a, *head_b, &moves);
		ft_best_move_condition_1(head_a, head_b, &moves);
		ft_best_move_condition_2(head_a, head_b, &moves);
		ft_best_move_condition_3(head_a, head_b, &moves);
		ft_best_move_condition_4(head_a, head_b, &moves);
		ft_push(head_b, head_a, 'a');
	}
	while (ft_check_ordered(head_a) != 1)
	{
		moves = ft_index_adjacent_info(*head_a);
		if (moves.pos <= moves.stack_middle)
			ft_rotate_stack(head_a, 'a');
		else if (moves.pos > moves.stack_middle)
			ft_reverse_rotate_stack(head_a, 'a');
	}
}
