/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:48:57 by destrada          #+#    #+#             */
/*   Updated: 2022/12/21 14:00:41 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_highest_to_lowest(t_stack **head)
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
		if (tmp->value < tmp->next->value)
			flag = 0;
		i++;
		tmp = tmp->next;
	}
	tmp->actual_pos = i;
	return (flag);
}

//clean_input.c
int	ft_checks1(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (ft_check_atoil(str) == 0)
		return (0);
	return (1);
}

int	ft_list_duplicates(t_stack *list)
{
	t_stack	*ptr;

	while (list->next != NULL)
	{
		ptr = list->next;
		while (ptr != NULL)
		{
			if (list->value == ptr->value)
				return (1);
			ptr = ptr->next;
		}
		list = list->next;
	}
	return (0);
}

int	ft_clean_and_create_stack_from_nargs(int argc,
	char **argv, t_pos *moves, t_stack **stack_a)
{
	moves->i = argc - 1;
	moves->max_index = argc - 1 - 1;
	moves->max_stack_size = argc - 1;
	while (moves->i > 0)
	{
		if (ft_checks1(argv[moves->i]) == 0)
			return (0);
		ft_insert_in_stack(stack_a, ft_atoi(argv[moves->i]));
		moves->i--;
	}
	if (ft_list_duplicates(*stack_a) == 1)
		return (0);
	moves->array = (int *)ft_calloc(moves->max_index + 1, sizeof(int));
	moves->i = 0;
	while (moves->i < (argc - 1))
	{
		moves->array[moves->i] = ft_atoi(argv[moves->i + 1]);
		moves->i = moves->i + 1;
	}
	return (1);
}

int	ft_clean_and_create_stack_from_string(char **argv, t_pos *moves,
		t_stack **stack_a)
{
	if (ft_check_only_spaces(moves, argv[1]) == 1)
		return (0);
	moves->each_value = ft_split(argv[1], ' ');
		moves->max_index = ft_wordcount(argv[1], ' ') - 1;
		moves->max_stack_size = ft_wordcount(argv[1], ' ');
		moves->i = moves->max_index;
	while (moves->i >= 0)
	{
		if (ft_checks1(moves->each_value[moves->i]) == 0)
			return (ft_free_doublechar(moves->each_value), 0);
		ft_insert_in_stack(stack_a,
			ft_atoi(moves->each_value[moves->i]));
		moves->i--;
	}
	if (ft_list_duplicates(*stack_a) == 1)
		return (ft_free_doublechar(moves->each_value), 0);
	ft_create_array_to_order(moves);
	return (1);
}
