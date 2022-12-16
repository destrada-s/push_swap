/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:54:38 by destrada          #+#    #+#             */
/*   Updated: 2022/12/16 14:12:33 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./mega_libft/libft.h"

typedef struct s_stack
{
	int					value;
	int					index;
	int					actual_pos;
	struct s_stack		*next;
}	t_stack;

typedef struct s_count
{
	int	i;
	int	j;
	int	k;
	int	middle;
	int	left_size;
	int	right_size;
	int	*left_half;
	int	*right_half;
}	t_count;

typedef struct s_pos
{
	int		pos;
	int		amount_of_adjacent_together;
	int		stack_size;
	int		stack_middle;
	int		max_index;
	int		max_stack_size;
	int		send_to_b_pos;
	int		best_in_b;
	int		send_is_closer_last;
	int		best_in_b_closer_last;
	int		cmp;
	int		i;
	int		*array;
	char	**each_value;
	int		neg_flag;
	t_stack	*tmp;
}	t_pos;

typedef struct s_best
{
	int		i;
	int		last;
	int		last_a;
	int		new;
	int		new_close;
	int		i_close;
	int		cmp;
	int		cmp_new;
	int		new_rev_close;
	int		i_rev_close;
}	t_best;

/*sorting algorithms*/

/*Create arrays and insert the content of left and half*/
t_count	ft_creat_arrays(int *array, t_count cnt, int left_index,
			int right_index);
/*sorting part part of the sorting part xd */
void	sort_halfof_merge(int *array, t_count *cnt);
/*The sorting part*/
void	ft_merge(int *array, int left_index, t_count cnt, int right_index);
/*merge sort - sorts by recurisveness dividing the array in left and right*/
void	ft_merge_sort(int *array, int left_index, int right_index);

/*sort stack with commands*/

void	sort_list_3(t_stack **head);
void	sort_list_3_inverse(t_stack **head);
void	sort_list_general_2(t_stack	**head_a, t_stack **head_b, t_pos moves);
void	sort_list_5(t_stack	**head_a, t_stack **head_b, t_pos moves);
void	ft_send_higher_to_lower(t_stack **head_a,
			t_stack **head_b, t_pos *moves);

/*check and create strings*/

int		ft_list_duplicates(t_stack *list);
int		ft_checks1(char *str);
int		ft_clean_and_create_stack_from_nargs(int argc,
			char **argv, t_pos *moves, t_stack **stack_a);
int		ft_clean_and_create_stack_from_string(char **argv, t_pos *moves,
			t_stack **stack_a);

/*list utils*/

/*list is empty?*/
int		list_is_empty(t_stack *head);
/* print lists*/
void	ft_print_list(t_stack *list);
/*print lists final index*/
void	ft_print_list_data(t_stack *list);
/*all data*/
void	ft_print_list_both_stacks_data(t_stack *stack_a, t_stack *stack_b);
/* find last in lists*/
t_stack	*ft_last_in_list(t_stack *list);
/* find second-last in lists*/
t_stack	*ft_2nlast_in_list(t_stack *list);
/*ordered lowest to highest*/
int		ft_check_lowest_to_highest(t_stack **head);
/*ordered highest to lowest*/
int		ft_check_highest_to_lowest(t_stack **head);
/*actualize position*/
void	actualize_pos(t_stack **head_a);

/*stacks commands*/

/*create node and insert in stack*/
t_stack	*ft_insert_in_stack(t_stack **head, int value);
/*swap first and second*/
void	ft_swap(t_stack **head, char stack);
/*move up the list and puts first as last*/
void	ft_rotate(t_stack **head);
/*move down the list and puts last as first*/
void	ft_reverse_rotate(t_stack **head);
/*move from one stack to another (from head_push to head_to_push)*/
void	ft_push(t_stack **head_push, t_stack **head_to_push, char pushfrom);
/*rotate stack*/
void	ft_rotate_stack(t_stack **head, char stack);
/*rotate stack*/
void	ft_reverse_rotate_stack(t_stack **head, char stack);
/*move up the list and puts first as last for both list*/
void	ft_rr(t_stack **head_a, t_stack **head_b);
/*move down the list and puts last as first for both lists*/
void	ft_rrr(t_stack **head_a, t_stack **head_b);
/*rr no print*/
void	ft_rr_only(t_stack **head_a, t_stack **head_b);
/*rrr no print*/
void	ft_rrr_only(t_stack **head_a, t_stack **head_b);

/*add actual_position and discover index - pos info && order*/

void	search_add_index_list(t_stack **head, int cmp, int index);
t_pos	allocate_index(t_stack **head, t_pos moves, int amount);
int		ft_check_ordered(t_stack **head);
int		ft_find_biggest(t_stack *list);
int		ft_find_lowest(t_stack *list);
int		adjacent_to_head_b(t_stack *head_a, t_stack *head_b, t_pos *moves);
int		ft_last_in_list_pos(t_stack *list);
t_pos	ft_index_adjacent_info(t_stack *head);
void	ft_best_solution_back(t_stack *head_a, t_stack *head_b, t_pos *moves);

/*more utils*/

/*free nodes*/
void	ft_stackclear(t_stack	**lst);
/*init struct*/
void	ft_init_moves(t_pos *moves);
/*print int array*/
void	ft_print_int_array(int *array, int amount);

/*checker*/

int		ft_doloop_for_inputs(char *lines, t_stack **stack_a, t_stack **stack_b);
/*push no print*/
void	ft_push_only(t_stack **head_push, t_stack **head_to_push);
/*swap in a and swap in b*/
void	ft_ss(t_stack **head_a, t_stack **head_b);
/*swap no print*/
void	ft_swap_only(t_stack **head);
int		ft_check_inputs(char *lines);
int		ft_check_only_spaces(t_pos *moves, char *str);
void	ft_create_array_to_order(t_pos *moves);
void	ft_use_commands(char *lines, t_stack **stack_a, t_stack **stack_b);

#endif