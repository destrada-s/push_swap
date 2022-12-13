/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_calculations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:38:32 by destrada          #+#    #+#             */
/*   Updated: 2022/12/13 18:43:21 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_best	ft_init_calculate_best_move(t_best calculate,
		t_stack *head_a, t_stack *head_b)
{
	calculate.i = 0;
	calculate.cmp = 0;
	calculate.last = ft_last_in_list_pos(head_b);
	calculate.last_a = ft_last_in_list_pos(head_a);
	calculate.new = 0;
	calculate.new_close = 0;
	calculate.i_close = 0;
	calculate.new_rev_close = 0;
	calculate.i_rev_close = 0;
	calculate.cmp_new = 0;
	return (calculate);
}

static	void	ft_most_important(t_best *calculate, t_pos *moves)
{
	if ((calculate->cmp > calculate->cmp_new)
		|| (moves->send_to_b_pos == -1)
		|| (calculate->cmp == calculate->cmp_new
			&& calculate->i_rev_close == calculate->new_rev_close))
	{
		calculate->cmp = calculate->cmp_new;
		moves->send_to_b_pos = calculate->new;
		moves->best_in_b = calculate->i;
		moves->send_is_closer_last = 0;
		moves->best_in_b_closer_last = 0;
		if (moves->send_to_b_pos
			> (calculate->last_a - moves->send_to_b_pos + 1))
		{
			moves->send_is_closer_last = 1;
			moves->send_to_b_pos
				= calculate->last_a - moves->send_to_b_pos + 1;
		}				
		if (moves->best_in_b > (calculate->last - moves->best_in_b + 1))
		{
				moves->best_in_b_closer_last = 1;
				moves->best_in_b = calculate->last - moves->best_in_b + 1;
		}
		if (calculate->cmp == 0)
			return ;
	}
}

static	void	ft_calculate_best_move_in_a_and_b(
		t_best *calculate, t_pos *moves)
{	
	calculate->new_rev_close = 0;
	calculate->new_close = calculate->new;
	if (calculate->new > (calculate->last_a - calculate->new + 1))
	{
		calculate->new_rev_close = 1;
		calculate->new_close = calculate->last_a - calculate->new + 1;
	}
		calculate->i_close = calculate->i;
		calculate->i_rev_close = 0;
	if (calculate->i > (calculate->last - calculate->i + 1))
	{
		calculate->i_rev_close = 1;
		calculate->i_close = calculate->last - calculate->i + 1;
	}
			calculate->cmp_new = calculate->new_close + calculate->i_close;
	ft_most_important(calculate, moves);
}

void	ft_best_solution_back(t_stack *head_a, t_stack *head_b, t_pos *moves)
{
	t_best	calculate;

	moves->send_to_b_pos = -1;
	calculate = ft_init_calculate_best_move(calculate, head_a, head_b);
	while (head_b != NULL)
	{
		calculate.new = adjacent_to_head_b(head_a, head_b, moves);
		if (calculate.new != -1)
		{
			ft_calculate_best_move_in_a_and_b(&calculate, moves);
		}
			head_b = head_b -> next;
			calculate.i++;
	}
}
