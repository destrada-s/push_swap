/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_command_stack2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:40:55 by destrada          #+#    #+#             */
/*   Updated: 2022/12/07 19:30:34 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_stack **head_a, t_stack **head_b)
{
	ft_rotate(head_a);
	ft_rotate(head_b);
	actualize_pos(head_a);
	actualize_pos(head_b);
	ft_printf("rr\n");
}

void	ft_rrr(t_stack **head_a, t_stack **head_b)
{
	ft_reverse_rotate(head_a);
	ft_reverse_rotate(head_b);
	actualize_pos(head_a);
	actualize_pos(head_b);
	ft_printf("rrr\n");
}

void	ft_rotate_stack(t_stack **head, char stack)
{
	ft_rotate(head);
	actualize_pos(head);
	ft_printf("r%c\n", stack);
}

void	ft_reverse_rotate_stack(t_stack **head, char stack)
{
	ft_reverse_rotate(head);
	actualize_pos(head);
	ft_printf("rr%c\n", stack);
}

void	ft_push(t_stack **head_push, t_stack **head_to_push, char pushfrom)
{
	t_stack	*send;

	send = (*head_push);
	(*head_push) = (*head_push)->next;
	send->next = *head_to_push;
	(*head_to_push) = send;
	actualize_pos(head_push);
	actualize_pos(head_to_push);
	ft_printf("p%c\n", pushfrom);
}
