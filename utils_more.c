/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:20:02 by destrada          #+#    #+#             */
/*   Updated: 2022/12/19 20:50:53 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackclear(t_stack	**lst)
{
	t_stack	*header;
	t_stack	*nextdel;

	header = *lst;
	while (header)
	{
		nextdel = header -> next;
		free(header);
		header = nextdel;
	}
	*lst = NULL;
}

void	ft_rr_only(t_stack **head_a, t_stack **head_b)
{
	ft_rotate(head_a);
	ft_rotate(head_b);
}

void	ft_rrr_only(t_stack **head_a, t_stack **head_b)
{
	ft_reverse_rotate(head_a);
	ft_reverse_rotate(head_b);
}

void	ft_create_array_to_order(t_pos *moves)
{
moves->array = (int *)ft_calloc(moves->max_index + 1, sizeof(int));
	moves->i = 0;
	while (moves->i < moves->max_index + 1)
	{
		moves->array[moves->i] = ft_atoi(moves->each_value[moves->i]);
		moves->i++;
	}
}

int	ft_check_only_spaces(t_pos *moves, char *str)
{
	int	flag_only_spaces;

	flag_only_spaces = 1;
	moves->i = 0;
	while (str[moves->i] != '\0')
	{
		if (str[moves->i] != ' ')
			flag_only_spaces = 0;
		moves->i++;
	}
	return (flag_only_spaces);
}
