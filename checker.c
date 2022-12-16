/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:06:09 by destrada          #+#    #+#             */
/*   Updated: 2022/12/16 13:38:48 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_and_create_stack_from_nargs(int argc,
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
	return (1);
}

int	ft_check_create_stack_from_string(char **argv, t_pos *moves,
		t_stack **stack_a)
{
	if (ft_check_only_spaces(moves, argv[1]))
		return (0);
	moves->each_value = ft_split(argv[1], ' ');
		moves->max_index = ft_wordcount(argv[1], ' ') - 1;
		moves->max_stack_size = ft_wordcount(argv[1], ' ');
		moves->i = moves->max_index;
	while (moves->i >= 0)
	{
		if (ft_checks1(moves->each_value[moves->i]) == 0)
			return (0);
		ft_insert_in_stack(stack_a,
			ft_atoi(moves->each_value[moves->i]));
		moves->i--;
	}
	if (ft_list_duplicates(*stack_a) == 1)
		return (0);
	return (1);
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
	moves->neg_flag = 0;
	moves->tmp = NULL;
}

int	ft_doloop_for_inputs(char *lines, t_stack **stack_a, t_stack **stack_b)
{
	while (0 == 0)
	{
		lines = get_next_line(0);
		if (!lines)
			break ;
		if (ft_check_inputs(lines) == 0)
			return (0);
		ft_use_commands(lines, stack_a, stack_b);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		*lines;
	t_pos		moves;

	stack_a = NULL;
	stack_b = NULL;
	lines = NULL;
	ft_init_moves(&moves);
	if (argc == 2)
		if (ft_clean_and_create_stack_from_string(argv,
				&moves, &stack_a) == 0)
			return (ft_putstr_fd("Error\n", 2), 255);
	if (argc > 2)
		if (ft_clean_and_create_stack_from_nargs(argc,
				argv, &moves, &stack_a) == 0)
			return (ft_putstr_fd("Error\n", 2), 255);
	if (ft_doloop_for_inputs(lines, &stack_a, &stack_b) == 0)
		return (ft_putstr_fd("Error\n", 2), 255);
	if (list_is_empty(stack_b) == 1
		&& ft_check_lowest_to_highest(&stack_a) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (ft_stackclear(&stack_a), ft_stackclear(&stack_b), 0);
}
