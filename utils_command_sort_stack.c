/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_command_sort_stack.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:54:08 by destrada          #+#    #+#             */
/*   Updated: 2022/12/12 20:14:55 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list_3(t_stack **head)
{
	/*Possibly need to make diffreent comparison because if using 2 stacks
		it may not be a good condition, should compare if in
		order from lowest to highest, this one useful for checking at the end when everithing is in A*/
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

//@ALL I THINK HERe IT SHOULD BE COMPARED THE AMOUNT OF ADJACENT MOVES
// IF REALLY ADJACENT 
//I COULD EVEN ADD THIS STUCT TO THE LIST TO TELL ME WHICH MOVE IS BETTER
//DEPENDIENDO DEL PESO DE MOVIMIENTOS 
//CAN BE CHANGED THE WHILE TO BREAK WHEN THE FIRST IF CONDTION
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
	while (list_is_empty(*head_b) != 1)
	{
		while (adjacent_to_head_b(*head_a, *head_b, moves) != 0)
		{
		/*FOR IT TOO WORK IT HAS TO FIND ADJACENT DOESNT CHECK NOT ADJACENT*/
			if (adjacent_to_head_b(*head_a, *head_b, moves)
				<= ft_last_in_list_pos(*head_a) / 2)
				ft_rotate_stack(head_a, 'a');
			else
				ft_reverse_rotate_stack(head_a, 'a');
		}
		ft_push(head_b, head_a, 'a');
	}
	while (ft_check_ordered(head_a) != 1)
	{
	//@ALL CHECK ORDER OF INDICES IF NODE < NODE-NEXT WHEN THIS IS TRUE DEPENDING ON HOW MUCH FROM THE LAST POS DO OR R OR RR
		moves = ft_index_adjacent_info(*head_a);
		if (moves.pos <= moves.stack_middle)
			ft_rotate_stack(head_a, 'a');
		else if (moves.pos > moves.stack_middle)
			ft_reverse_rotate_stack(head_a, 'a');
	}	
}

 /* Add  moves for b when getting*/
void	sort_list_general_2(t_stack	**head_a, t_stack **head_b, t_pos moves)
{
 	if (ft_check_ordered(head_a) != 1)
 	{
 		while (ft_last_in_list_pos(*head_a) != 2)
 		{	
			 if (list_is_empty(*head_b) == 1)
			{
				while (ft_find_lowest_relnposes_changes(*head_a, 10) != 0)
				{
					if (ft_find_lowest_relnposes_changes(*head_a, 10)
						<= ft_last_in_list_pos(*head_a) / 2)
						ft_rotate_stack(head_a, 'a');
					else
						ft_reverse_rotate_stack(head_a, 'a');
				}	
			}
			ft_push(head_a, head_b, 'b');
			if (ft_last_in_list_pos(*head_a) < 100)
			{
				//CREAR LOS  BUCLES , TENDRIAS QUE TENER DIFERENCIA EN CUENTA  4 condiciones de bucles ...
				moves = ft_best_solution(*head_a, *head_b, moves, 3);
				if (moves.best_in_b_closer_last == 1 && moves.send_is_closer_last == 1)
				{
					while (moves.best_in_b !=  0 && moves.send_to_b_pos != 0)
					{
						ft_rrr(head_a, head_b);
						moves.best_in_b--;
						moves.send_to_b_pos--;
					}
					while (moves.best_in_b != 0)
					{
						ft_reverse_rotate_stack(head_b, 'b');
						moves.best_in_b--;
					}
					while (moves.send_to_b_pos != 0)
					{
						ft_reverse_rotate_stack(head_a, 'a');
						moves.send_to_b_pos--;
					}
				}
				else if (moves.best_in_b_closer_last == 0 && moves.send_is_closer_last == 0)
				{
						while (moves.best_in_b !=  0 && moves.send_to_b_pos != 0)
					{
						ft_rr(head_a, head_b);
						moves.best_in_b--;
						moves.send_to_b_pos--;
					}
					while (moves.best_in_b != 0)
					{
						ft_rotate_stack(head_b, 'b');
						moves.best_in_b--;
					}
					while (moves.send_to_b_pos != 0)
					{
						ft_rotate_stack(head_a, 'a');
						moves.send_to_b_pos--;
					}
				}
				else if (moves.best_in_b_closer_last == 0 && moves.send_is_closer_last == 1)
				{
					while (moves.best_in_b != 0)
					{
						ft_rotate_stack(head_b, 'b');
						moves.best_in_b--;
					}
					while (moves.send_to_b_pos != 0)
					{
						ft_reverse_rotate_stack(head_a, 'a');
						moves.send_to_b_pos--;
					}
				}
				else if (moves.best_in_b_closer_last == 1 && moves.send_is_closer_last == 0)
				{
					while (moves.best_in_b != 0)
					{
						ft_reverse_rotate_stack(head_b, 'b');
						moves.best_in_b--;
					}
					while (moves.send_to_b_pos != 0)
					{
						ft_rotate_stack(head_a, 'a');
						moves.send_to_b_pos--;
					}
				}
			}
			else if (ft_last_in_list_pos(*head_a) < 300)
			{
				moves = ft_best_solution(*head_a, *head_b, moves, 7);
				if (moves.best_in_b_closer_last == 1 && moves.send_is_closer_last == 1)
				{
					while (moves.best_in_b !=  0 && moves.send_to_b_pos != 0)
					{
						ft_rrr(head_a, head_b);
						moves.best_in_b--;
						moves.send_to_b_pos--;
					}
					while (moves.best_in_b != 0)
					{
						ft_reverse_rotate_stack(head_b, 'b');
						moves.best_in_b--;
					}
					while (moves.send_to_b_pos != 0)
					{
						ft_reverse_rotate_stack(head_a, 'a');
						moves.send_to_b_pos--;
					}
				}
				else if (moves.best_in_b_closer_last == 0 && moves.send_is_closer_last == 0)
				{
						while (moves.best_in_b !=  0 && moves.send_to_b_pos != 0)
					{
						ft_rr(head_a, head_b);
						moves.best_in_b--;
						moves.send_to_b_pos--;
					}
					while (moves.best_in_b != 0)
					{
						ft_rotate_stack(head_b, 'b');
						moves.best_in_b--;
					}
					while (moves.send_to_b_pos != 0)
					{
						ft_rotate_stack(head_a, 'a');
						moves.send_to_b_pos--;
					}
				}
				else if (moves.best_in_b_closer_last == 0 && moves.send_is_closer_last == 1)
				{
					while (moves.best_in_b != 0)
					{
						ft_rotate_stack(head_b, 'b');
						moves.best_in_b--;
					}
					while (moves.send_to_b_pos != 0)
					{
						ft_reverse_rotate_stack(head_a, 'a');
						moves.send_to_b_pos--;
					}
				}
				else if (moves.best_in_b_closer_last == 1 && moves.send_is_closer_last == 0)
				{
					while (moves.best_in_b != 0)
					{
						ft_reverse_rotate_stack(head_b, 'b');
						moves.best_in_b--;
					}
					while (moves.send_to_b_pos != 0)
					{
						ft_rotate_stack(head_a, 'a');
						moves.send_to_b_pos--;
					}
				}
			}
			else
			{
				moves = ft_best_solution(*head_a, *head_b, moves, 10);
				if (moves.best_in_b_closer_last == 1 && moves.send_is_closer_last == 1)
				{
					while (moves.best_in_b !=  0 && moves.send_to_b_pos != 0)
					{
						ft_rrr(head_a, head_b);
						moves.best_in_b--;
						moves.send_to_b_pos--;
					}
					while (moves.best_in_b != 0)
					{
						ft_reverse_rotate_stack(head_b, 'b');
						moves.best_in_b--;
					}
					while (moves.send_to_b_pos != 0)
					{
						ft_reverse_rotate_stack(head_a, 'a');
						moves.send_to_b_pos--;
					}
				}
				else if (moves.best_in_b_closer_last == 0 && moves.send_is_closer_last == 0)
				{
						while (moves.best_in_b !=  0 && moves.send_to_b_pos != 0)
					{
						ft_rr(head_a, head_b);
						moves.best_in_b--;
						moves.send_to_b_pos--;
					}
					while (moves.best_in_b != 0)
					{
						ft_rotate_stack(head_b, 'b');
						moves.best_in_b--;
					}
					while (moves.send_to_b_pos != 0)
					{
						ft_rotate_stack(head_a, 'a');
						moves.send_to_b_pos--;
					}
				}
				else if (moves.best_in_b_closer_last == 0 && moves.send_is_closer_last == 1)
				{
					while (moves.best_in_b != 0)
					{
						ft_rotate_stack(head_b, 'b');
						moves.best_in_b--;
					}
					while (moves.send_to_b_pos != 0)
					{
						ft_reverse_rotate_stack(head_a, 'a');
						moves.send_to_b_pos--;
					}
				}
				else if (moves.best_in_b_closer_last == 1 && moves.send_is_closer_last == 0)
				{
					while (moves.best_in_b != 0)
					{
						ft_reverse_rotate_stack(head_b, 'b');
						moves.best_in_b--;
					}
					while (moves.send_to_b_pos != 0)
					{
						ft_rotate_stack(head_a, 'a');
						moves.send_to_b_pos--;
					}
				}
			}
				
		}
		sort_list_3(head_a);
 	}
 	while (list_is_empty(*head_b) != 1)
 	{
		moves = ft_best_solution_back(*head_a, *head_b, moves);
				if (moves.best_in_b_closer_last == 1 && moves.send_is_closer_last == 1)
				{
					while (moves.best_in_b !=  0 && moves.send_to_b_pos != 0)
					{
						ft_rrr(head_a, head_b);
						moves.best_in_b--;
						moves.send_to_b_pos--;
					}
					while (moves.best_in_b != 0)
					{
						ft_reverse_rotate_stack(head_b, 'b');
						moves.best_in_b--;
					}
					while (moves.send_to_b_pos != 0)
					{
						ft_reverse_rotate_stack(head_a, 'a');
						moves.send_to_b_pos--;
					}
				}
				else if (moves.best_in_b_closer_last == 0 && moves.send_is_closer_last == 0)
				{
						while (moves.best_in_b !=  0 && moves.send_to_b_pos != 0)
					{
						ft_rr(head_a, head_b);
						moves.best_in_b--;
						moves.send_to_b_pos--;
					}
					while (moves.best_in_b != 0)
					{
						ft_rotate_stack(head_b, 'b');
						moves.best_in_b--;
					}
					while (moves.send_to_b_pos != 0)
					{
						ft_rotate_stack(head_a, 'a');
						moves.send_to_b_pos--;
					}
				}
				else if (moves.best_in_b_closer_last == 0 && moves.send_is_closer_last == 1)
				{
					while (moves.best_in_b != 0)
					{
						ft_rotate_stack(head_b, 'b');
						moves.best_in_b--;
					}
					while (moves.send_to_b_pos != 0)
					{
						ft_reverse_rotate_stack(head_a, 'a');
						moves.send_to_b_pos--;
					}
				}
				else if (moves.best_in_b_closer_last == 1 && moves.send_is_closer_last == 0)
				{
					while (moves.best_in_b != 0)
					{
						ft_reverse_rotate_stack(head_b, 'b');
						moves.best_in_b--;
					}
					while (moves.send_to_b_pos != 0)
					{
						ft_rotate_stack(head_a, 'a');
						moves.send_to_b_pos--;
					}
				}
 		// while (adjacent_to_head_b(*head_a, *head_b, moves) != 0)
 		// {
 		// 	if (adjacent_to_head_b(*head_a, *head_b, moves)
 		// 		<= ft_last_in_list_pos(*head_a) / 2)
 		// 		ft_rotate_stack(head_a, 'a');
 		// 	else
 		// 		ft_reverse_rotate_stack(head_a, 'a');
 		// } 
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
 	//ft_print_list_both_stacks_data(*head_a, *head_b);
 }

// relative takes into account pos and final index A BIT WORSE THAN GENERAL 1
void	sort_list_general_3(t_stack	**head_a, t_stack **head_b, t_pos moves)
{
 	if (ft_check_ordered(head_a) != 1)
 	{
 		while (ft_last_in_list_pos(*head_a) != 2)
 		{	
			 if (list_is_empty(*head_b) == 1)
			{
				while (ft_find_lowest_relnposes_changes(*head_a, 10) != 0)
				{
					if (ft_find_lowest_relnposes_changes(*head_a, 10)
						<= ft_last_in_list_pos(*head_a) / 2)
						ft_rotate_stack(head_a, 'a');
					else
						ft_reverse_rotate_stack(head_a, 'a');	
				}
			}
			ft_push(head_a, head_b, 'b');
			if (ft_last_in_list_pos(*head_a) < 100)
			{
				while (send_to_head_b_relnchanges(*head_a, *head_b, moves, 3) != 0)
				{
					if (send_to_head_b_relnchanges(*head_a, *head_b, moves, 3)
							<= ft_last_in_list_pos(*head_a) / 2)
							ft_rotate_stack(head_a, 'a');
					else
							ft_reverse_rotate_stack(head_a, 'a');
				}
				
			}
				else if (ft_last_in_list_pos(*head_a) < 300)
			{
				while (send_to_head_b_relnchanges(*head_a, *head_b, moves, 7) != 0)
				{
					if (send_to_head_b_relnchanges(*head_a, *head_b, moves, 7)
							<= ft_last_in_list_pos(*head_a) / 2)
							ft_rotate_stack(head_a, 'a');
					else
							ft_reverse_rotate_stack(head_a, 'a');
				}
			}
			else
			{
					while (send_to_head_b_relnchanges(*head_a, *head_b, moves, 10) != 0)
				{
					if (send_to_head_b_relnchanges(*head_a, *head_b, moves, 10)
							<= ft_last_in_list_pos(*head_a) / 2)
							ft_rotate_stack(head_a, 'a');
					else
							ft_reverse_rotate_stack(head_a, 'a');
				}
			}
		}
		sort_list_3(head_a);
 	}
	
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
 	while (ft_check_ordered(head_a) != 1)
 	{
 		moves = ft_index_adjacent_info(*head_a);
 		if (moves.pos <= moves.stack_middle)
 			ft_rotate_stack(head_a, 'a');
 		else if (moves.pos > moves.stack_middle)
 			ft_reverse_rotate_stack(head_a, 'a');
 	}	
 	//ft_print_list_both_stacks_data(*head_a, *head_b);
}
