/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:05:38 by destrada          #+#    #+#             */
/*   Updated: 2022/12/11 16:13:22 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// utils_lists_more.c
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
//When entered as various arguments
// Dont know if gets plus sign
int	ft_checks1(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
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

int	main(int argc, char **argv)
{
	int			i;
	int			*array;
	char		**each_value;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_pos		moves;

	i = argc - 1;
	stack_a = NULL;
	stack_b = NULL;
	array = NULL;
	if (argc > 1)
	{
		if (argc == 2)
		{
			each_value = ft_split(argv[1], ' ');
			moves.max_index = ft_wordcount(argv[1], ' ') - 1;
			moves.max_stack_size = ft_wordcount(argv[1], ' ');
			i = moves.max_index;
			while (i >= 0)
			{
				if (ft_checks1(each_value[i]) == 0)
					return (ft_putstr_fd("Error\n", 2), 255);
				ft_insert_in_stack(&stack_a, ft_atoi(each_value[i]));
				i--;
			}
			if (ft_list_duplicates(stack_a) == 1)
				return (ft_putstr_fd("Error\n", 2), 0);
			array = (int *)ft_calloc(moves.max_index + 1, sizeof(int));
			i = 0;
			while (i < moves.max_index + 1)
			{
				array[i] = ft_atoi(each_value[i]);
				i++;
			}
		}
		else
		{
			moves.max_index = argc - 1 - 1;
			moves.max_stack_size = argc - 1;
			while (i > 0)
			{
				if (ft_checks1(argv[i]) == 0)
					return (ft_putstr_fd("Error\n", 2), 255);
				ft_insert_in_stack(&stack_a, ft_atoi(argv[i]));
				i--;
			}
			if (ft_list_duplicates(stack_a) == 1)
				return (ft_putstr_fd("Error\n", 2), 255);
			array = (int *)ft_calloc(moves.max_index + 1, sizeof(int));
			i = 0;
			while (i < argc - 1)
			{
				array[i] = ft_atoi(argv[i + 1]);
				i++;
			}
		}
		ft_merge_sort(array, 0, i - 1);
		moves = allocate_index(&stack_a, array, moves.max_index + 1);
		if (moves.max_index < 5)
			sort_list_5(&stack_a, &stack_b, moves);
	//	else if (moves.max_index < 100)
	//		sort_list_general(&stack_a, &stack_b, moves);
		else
			sort_list_general_2(&stack_a, &stack_b, moves);
	}
	//ft_print_list_both_stacks_data(stack_a, stack_b);
	return (0);
}

//Should I always look for the actual pos after a move??
//Take in to account the final index pos? Is it useful
//Make use of peso de la posicion??
//Create algorithm for 3, 5 and 100

//NEED TO MAKE ANTI DUPLICATES  AUN FALTA
//NEED tO MAKE CLEANER FOR 2 ARGS
//GENERAL ALGORITHM
// MAKE IT WORK FOR RR and RRR
//CLEANER DONE FOR WHEN VARIOUS ARGS 
// IF string left 0 Cleaner and space cleaner 
