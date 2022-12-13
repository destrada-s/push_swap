/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:05:38 by destrada          #+#    #+#             */
/*   Updated: 2022/12/13 20:23:00 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ASK TOMORROW TO LOOK FOR LEAKS QUE NO SABES
void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

void	ft_stackclear(t_list **stack)
{
	t_list	*header;
	t_list	*nextdel;

	header = *stack;
	while (header)
	{
		nextdel = header -> next;
		free(header -> content);
		free(header);
		header = nextdel;
	}
	*stack = NULL;
}

/*part of algortitm*/
void	ft_send_higher_to_lower(t_stack **head_a,
		t_stack **head_b, t_pos *moves)
{
	if (ft_check_ordered(head_a) != 1)
	{
		while (ft_last_in_list_pos(*head_a) != 2)
		{
			while (ft_last_in_list_pos(*head_a) > (moves->max_index + 1) / 2)
			{
				if ((*head_a)->index < ((moves->max_index + 1) / 2))
					ft_push(head_a, head_b, 'b');
				else
					ft_rotate_stack(head_a, 'a');
			}
			ft_push(head_a, head_b, 'b');
		}
		sort_list_3(head_a);
	}
}

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
	moves->diff = 0;
	moves->least_diff = 0;
	moves->pos2 = 0;
	moves->neg_flag = 0;
	moves->tmp = NULL;
}

//still need to check if string is NULL to give error
//check leaks
//do checker