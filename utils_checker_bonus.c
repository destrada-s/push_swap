/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:10:54 by destrada          #+#    #+#             */
/*   Updated: 2022/12/19 18:19:33 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_only(t_stack **head)
{
	t_stack	*tmp;

	if (!(*head) || !((*head)->next))
		return ;
	tmp = *head;
	tmp = tmp->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
}

void	ft_ss(t_stack **head_a, t_stack **head_b)
{
	ft_swap_only(head_a);
	ft_swap_only(head_b);
}

void	ft_push_only(t_stack **head_push, t_stack **head_to_push)
{
	t_stack	*send;

	if (!(*head_push))
		return ;
	send = (*head_push);
	(*head_push) = (*head_push)->next;
	send->next = *head_to_push;
	(*head_to_push) = send;
}

int	ft_check_inputs(char *lines)
{
	if (ft_strncmp(lines, "sa\n", 3) == 0 || ft_strncmp(lines, "sb\n", 3) == 0
		|| ft_strncmp(lines, "ss\n", 3) == 0)
		return (1);
	else if (ft_strncmp(lines, "ra\n", 3) == 0
		|| ft_strncmp(lines, "rb\n", 3) == 0
		|| ft_strncmp(lines, "rr\n", 3) == 0)
		return (1);
	else if (ft_strncmp(lines, "rra\n", 4) == 0
		|| ft_strncmp(lines, "rrb\n", 4) == 0
		|| ft_strncmp(lines, "rrr\n", 4) == 0)
		return (1);
	else if (ft_strncmp(lines, "pa\n", 3) == 0
		|| ft_strncmp(lines, "pb\n", 3) == 0)
		return (1);
	return (0);
}

void	ft_use_commands(char *lines, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(lines, "sa\n", 3) == 0)
		ft_swap_only(stack_a);
	else if (ft_strncmp(lines, "sb\n", 3) == 0)
		ft_swap_only(stack_b);
	else if (ft_strncmp(lines, "ss\n", 3) == 0)
		ft_ss(stack_a, stack_b);
	else if (ft_strncmp(lines, "ra\n", 3) == 0)
		ft_rotate(stack_a);
	else if (ft_strncmp(lines, "rb\n", 3) == 0)
		ft_rotate(stack_b);
	else if (ft_strncmp(lines, "rr\n", 3) == 0)
		ft_rr_only(stack_a, stack_b);
	else if (ft_strncmp(lines, "rra\n", 4) == 0)
		ft_reverse_rotate(stack_a);
	else if (ft_strncmp(lines, "rrb\n", 4) == 0)
		ft_reverse_rotate(stack_b);
	else if (ft_strncmp(lines, "rrr\n", 4) == 0)
		ft_rrr_only(stack_a, stack_b);
	else if (ft_strncmp(lines, "pb\n", 3) == 0)
		ft_push_only(stack_a, stack_b);
	else if (ft_strncmp(lines, "pa\n", 3) == 0)
		ft_push_only(stack_b, stack_a);
}
