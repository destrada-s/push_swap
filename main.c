/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:22:30 by destrada          #+#    #+#             */
/*   Updated: 2022/12/15 17:59:48 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_pos		moves;

	stack_a = NULL;
	stack_b = NULL;
	ft_init_moves(&moves);
	if (argc == 2)
		if (ft_clean_and_create_stack_from_string(argv,
				&moves, &stack_a) == 0)
			return (ft_putstr_fd("Error\n", 2), 255);
	if (argc > 2)
		if (ft_clean_and_create_stack_from_nargs(argc,
				argv, &moves, &stack_a) == 0)
			return (ft_putstr_fd("Error\n", 2), 255);
	ft_merge_sort(moves.array, 0, moves.i - 1);
	moves = allocate_index(&stack_a, moves, moves.max_index + 1);
	if (moves.max_index < 5)
		sort_list_5(&stack_a, &stack_b, moves);
	else
		sort_list_general_2(&stack_a, &stack_b, moves);
	return (ft_stackclear(&stack_a), 0);
}
