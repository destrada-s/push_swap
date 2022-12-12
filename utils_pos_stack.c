/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pos_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:54:52 by destrada          #+#    #+#             */
/*   Updated: 2022/12/12 20:21:43 by destrada         ###   ########.fr       */
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

t_pos	allocate_index(t_stack **head, int	*array, int amount)
{
	t_pos	moves;
	int		i;

	i = 0;
	moves.max_index = 0;
	while (i < amount)
	{
		search_add_index_list(head, array[i], i);
		i++;
	}
	moves.max_index = i - 1;
	actualize_pos(head);
	return (moves);
}

/*Could also give the new actual positions here if needed and not ordered yet;
Lowest to HIGHEST need another check for b (highest to lowest) */
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

int	adjacent_to_head_b(t_stack *head_a, t_stack *head_b, t_pos moves)
{
	int		least_diff;
	int		diff;
	int		pos2;
	int		neg_flag;
	t_stack	*tmp;

	diff = 0;
	pos2 = 0;
	tmp = head_a;
	neg_flag = 1;
	least_diff = 0;
	if (head_b->index == moves.max_index)
		return (ft_find_lowest(head_a));
	while (head_a != NULL)
	{
		diff = head_a->index - head_b->index;
		if (diff > 0)
			neg_flag = 0;
		if (diff == 1)
			return (head_a->actual_pos);
		else if ((diff > 0 && least_diff > diff) || (least_diff == 0 && diff > 0))
		{
			least_diff = diff;
			pos2 = head_a->actual_pos;
		}
		head_a = head_a -> next;
	}
	if (neg_flag == 1)
		return (ft_find_lowest(tmp));
	return (pos2);
}

int	ft_find_lowest_relnposes_changes(t_stack *list, int n)
{
	t_stack	*lowest;
	int		flag;
	int		last;
	int		cmp;
	int		cmpnew;
	int 	close;

	flag = 1;
	lowest = list;
	last = ft_last_in_list_pos(list);
	close = list->actual_pos;
	if (list->actual_pos >  last - list->actual_pos)
		close = last - list->actual_pos + 1;
	cmp = close + list->index;
	while (list != NULL)
	{
		close = list->actual_pos;
		if (list->actual_pos >  last - list->actual_pos)
		close = last - list->actual_pos + 1;
		cmpnew = close + list->index;
		if (cmp > cmpnew || (cmp == cmpnew && lowest->index > list->index))
		{
			lowest = list;
			cmp = cmpnew;
		}
		if (list->actual_pos == (n) && flag == 1)
		{
			flag = 0;
			while (list -> actual_pos < (last - n - 1))
				list = list -> next;
		}
		else
			list = list -> next;
	}
	return (lowest->actual_pos);
}

t_pos	ft_best_solution(t_stack *head_a, t_stack *head_b, t_pos moves, int n)
{
	int		i;
	int		last;
	int		last_a;
	int		new;
	int		i_close;
	int 	cmp;
	int 	cmp_new;
	int 	flag;
	t_pos	info_new;
	int		diff;

	flag = 1;
	i = 0;
	cmp = 0;
	moves.send_to_b_pos = -1;
	last = ft_last_in_list_pos(head_b);
	last_a = ft_last_in_list_pos(head_a);
	new = 0;
	i_close = 0;
	cmp_new = 0;
	diff = 0;
	/*Init t_pos*/
	info_new.amount_of_adjacent_together = 0;
	info_new.best_in_b = 0;
	info_new.best_in_b_closer_last = 0;
	info_new.cmp = 0;
	info_new.diff_adjacent = 0;
	info_new.max_index = 0;
	info_new.max_stack_size = 0;
	info_new.pos = 0;
	info_new.send_is_closer_last = 0;
	info_new.stack_middle = 0;
	info_new.stack_size = 0;

	while (head_b != NULL)
	{ // TAKE INTO ACCOUNT DIFF NOT ONLY BEST MOVES?
		new = send_to_head_b_relnchanges(head_a, head_b, moves, n);
		info_new = send_to_head_b_relncmp(head_a, head_b, moves, n);
		//i_close = i;
		if (i > (last - i + 1))
				i_close = last - i + 1;
		cmp_new = info_new.cmp + i_close;
		if ((cmp > cmp_new) || (moves.send_to_b_pos == -1) || (cmp == cmp_new && diff > info_new.diff_adjacent ))
		{
			cmp = cmp_new;
			diff = info_new.diff_adjacent;
			moves.send_to_b_pos = new;
			moves.best_in_b = i;
			moves.send_is_closer_last = 0;
			moves.best_in_b_closer_last = 0;
			if (moves.send_to_b_pos > (last_a - moves.send_to_b_pos + 1))
			{
				moves.send_is_closer_last = 1;
				moves.send_to_b_pos = last_a - moves.send_to_b_pos + 1;
			}
			if (moves.best_in_b > (last - moves.best_in_b + 1))
			{
				moves.best_in_b_closer_last = 1;
				moves.best_in_b = last - moves.best_in_b + 1;
			}
		}
		if (head_b->actual_pos == n && flag == 1)
		{
			flag = 0;
			while (head_b -> actual_pos < (last - n - 1))
			{
				head_b = head_b -> next;
				i++;
			}
		}
		else
		{
			head_b = head_b -> next;
			i++;
		}
	}
	return (moves);
}

int	send_to_head_b_relnchanges(t_stack *head_a, t_stack *head_b, t_pos moves, int n)
{
	int		least_diff;
	int		diff;
	t_stack	*pos2;
	int		neg_flag;
	t_stack	*tmp;
	int 	last;
	int		flag;
	int		cmp;
	int		cmpnew;
	int		close;

	flag = 1;
	last = ft_last_in_list_pos(head_a);
	diff = 0;
	pos2 = 0;
	least_diff = 0;
	cmp = 0;
	tmp = head_a;
	neg_flag = 1;
	if (head_b->index == moves.max_index)
		return (ft_find_lowest_relnposes_changes(head_a, n));
	while (head_a != NULL)
	{
		diff = head_a->index - head_b->index;
		close = head_a->actual_pos;
		if (close > (last - head_a->actual_pos + 1))
			close = last - head_a ->actual_pos + 1;
		cmpnew = (diff - 1) + close;
		if (diff > 0)
			neg_flag = 0;
		if (diff > 0 && (least_diff == 0 || cmp > cmpnew || (cmp == cmpnew && least_diff > diff)))
		{
			least_diff = diff;
			cmp = cmpnew;
			pos2 = head_a;
		}
		if (head_a->actual_pos == n && flag == 1)
		{
			flag = 0;
			while (head_a -> actual_pos < (last - n - 1))
				head_a = head_a -> next;
		}
		else
			head_a = head_a -> next;
	}
	if (neg_flag == 1)
		return (ft_find_lowest_relnposes_changes(tmp, n));
	return (pos2->actual_pos);
}

t_pos	send_to_head_b_relncmp(t_stack *head_a, t_stack *head_b, t_pos moves, int n)
{
	int		diff;
	int		neg_flag;
	t_stack	*tmp;
	int 	last;
	int		flag;
	int		cmpnew;
	int		close;

	flag = 1;
	last = ft_last_in_list_pos(head_a);
	diff = 0;
	moves.diff_adjacent = 0;
	moves.cmp = 0;
	tmp = head_a;
	neg_flag = 1;
	if (head_b->index == moves.max_index)
		return (ft_find_lowest_relncmp(head_a, moves, n));
	while (head_a != NULL)
	{
		diff = head_a->index - head_b->index;
		close = head_a->actual_pos;
		if (close > (last - head_a->actual_pos + 1))
			close = last - head_a ->actual_pos + 1;
		cmpnew = (diff - 1) + close;
		if (diff > 0)
			neg_flag = 0;
		if (diff > 0 && (moves.diff_adjacent == 0 || moves.cmp > cmpnew || (moves.cmp == cmpnew && moves.diff_adjacent > diff)))
		{
			moves.diff_adjacent = diff;
			moves.cmp = cmpnew;
		}
		if (head_a->actual_pos == n && flag == 1)
		{
			flag = 0;
			while (head_a -> actual_pos < (last - n - 1))
				head_a = head_a -> next;
		}
		else
			head_a = head_a -> next;
	}
	if (neg_flag == 1)
		return (ft_find_lowest_relncmp(tmp, moves, n));
	return (moves);
}

t_pos	ft_find_lowest_relncmp(t_stack *list, t_pos moves, int n)
{
	t_stack	*lowest;
	int		flag;
	int		last;
	int		cmpnew;
	int 	close;

	flag = 1;
	lowest = list;
	last = ft_last_in_list_pos(list);
	close = list->actual_pos;
	if (list->actual_pos >  last - list->actual_pos)
		close = last - list->actual_pos + 1;
	moves.cmp = close + list->index;
	while (list != NULL)
	{
		close = list->actual_pos;
		if (list->actual_pos >  last - list->actual_pos)
		close = last - list->actual_pos + 1;
		cmpnew = close + list->index;
		if (moves.cmp > cmpnew || (moves.cmp == cmpnew && lowest->index > list->index))
		{
			lowest = list;
			moves.cmp = cmpnew;
			moves.diff_adjacent = -1;
		}
		if (list->actual_pos == (n) && flag == 1)
		{
			flag = 0;
			while (list -> actual_pos < (last - n - 1))
				list = list -> next;
		}
		else
			list = list -> next;
	}
	return (moves);
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

int	ft_2nlast_in_list_pos(t_stack *list)
{
	while (list->next->next != NULL)
	{
		list = list->next;
	}
	return (list->actual_pos);
}

t_pos	ft_best_solution_back(t_stack *head_a, t_stack *head_b, t_pos moves)
{
	int		i;
	int		last;
	int		last_a;
	int		new;
	int		new_close;
	int		i_close;
	int 	cmp;
	int 	cmp_new;
	int 	flag;
	int		diff;
	int		new_rev_close;
	int		i_rev_close;

	flag = 1;
	i = 0;
	cmp = 0;
	moves.send_to_b_pos = -1;
	last = ft_last_in_list_pos(head_b);
	last_a = ft_last_in_list_pos(head_a);
	new = 0;
	new_close = 0;
	i_close = 0;
	new_rev_close = 0;
	i_rev_close = 0;
	cmp_new = 0;
	diff = 0;

	while (head_b != NULL)
	{ // TAKE INTO ACCOUNT DIFF NOT ONLY BEST MOVES?
		new = adjacent_to_head_b(head_a, head_b, moves);
		if (new != -1)
		{
			new_rev_close = 0;
			new_close = new;
			if (new > (last_a - new + 1))
			{
				new_rev_close = 1;
				new_close = last_a - new + 1;
			}
			i_close = i;
			i_rev_close = 0;
			if (i > (last - i + 1))
			{
				i_rev_close = 1;
				i_close = last - i + 1;
			}
			cmp_new = new_close + i_close;
			if ((cmp > cmp_new) || (moves.send_to_b_pos == -1) || (cmp == cmp_new && i_rev_close == new_rev_close))
			{
				cmp = cmp_new;
				moves.send_to_b_pos = new;
				moves.best_in_b = i;
				moves.send_is_closer_last = 0;
				moves.best_in_b_closer_last = 0;
				if (moves.send_to_b_pos > (last_a - moves.send_to_b_pos + 1))
				{
					moves.send_is_closer_last = 1;
					moves.send_to_b_pos = last_a - moves.send_to_b_pos + 1;
				}
				if (moves.best_in_b > (last - moves.best_in_b + 1))
				{
					moves.best_in_b_closer_last = 1;
					moves.best_in_b = last - moves.best_in_b + 1;
				}
				if (cmp == 0)
					return (moves);
			}
		}
			head_b = head_b -> next;
			i++;
	}
	return (moves);
}

int	only_adjacent_to_head_b(t_stack *head_a, t_stack *head_b, t_pos moves)
{
	int		diff;
	t_stack	*tmp;
	int		neg_flag;

	diff = 0;
	neg_flag = 0;
	tmp = head_a;
	if (head_b->index == moves.max_index)
		return (ft_find_lowest(head_a));
	while (head_a != NULL)
	{
		diff = head_a->index - head_b->index;
		if (diff > 0)
			neg_flag = 1;

		if (diff == 1)
			return (head_a->actual_pos);
		head_a = head_a -> next;
	}
	if (neg_flag == 1)
		return (ft_find_lowest(head_a));
	return (-1);
}
