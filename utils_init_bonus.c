/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:51:28 by destrada          #+#    #+#             */
/*   Updated: 2022/12/21 15:56:34 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_moves(t_pos *moves)
{
	moves->amount_of_adjacent_together = 0;
	moves->array = NULL;
	moves->best_in_b = 0;
	moves->best_in_b_closer_last = 0;
	moves->cmp = 0;
	moves->each_value = NULL;
	moves->i = 0;
	moves->max_index = 0;
	moves->max_stack_size = 0;
	moves->pos = 0;
	moves->send_is_closer_last = 0;
	moves->send_to_b_pos = 0;
	moves->stack_middle = 0;
	moves->stack_size = 0;
	moves->least_diff = 0;
	moves->diff = 0;
	moves->pos2 = 0;
	moves->neg_flag = 0;
	moves->tmp = NULL;
}
