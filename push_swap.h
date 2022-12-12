/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:54:38 by destrada          #+#    #+#             */
/*   Updated: 2022/12/12 18:31:43 by destrada         ###   ########.fr       */
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
	int	pos;
	int	amount_of_adjacent_together;
	int	stack_size;
	int	stack_middle;
	int	max_index;
	int	max_stack_size;
	int	send_to_b_pos;
	int	best_in_b;
	int	send_is_closer_last;
	int	best_in_b_closer_last;
	int	diff_adjacent;
	int	cmp;
}	t_pos;

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

/*It works correctly but not great efficiency*/
void	sort_list_3(t_stack **head);
void	sort_list_3_inverse(t_stack **head);
void	sort_list_general(t_stack	**head_a, t_stack **head_b, t_pos moves);
void	sort_list_general_1(t_stack	**head_a, t_stack **head_b, t_pos moves);
void	sort_list_general_2(t_stack	**head_a, t_stack **head_b, t_pos moves);
void	sort_list_general_3(t_stack	**head_a, t_stack **head_b, t_pos moves);
void	sort_list_5(t_stack	**head_a, t_stack **head_b, t_pos moves);
int		only_adjacent_to_head_b(t_stack *head_a, t_stack *head_b, t_pos moves);

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

/*add actual_position and discover index - pos info && order*/

void	search_add_index_list(t_stack **head, int cmp, int index);
t_pos	allocate_index(t_stack **head, int	*array, int amount);
int		ft_check_ordered(t_stack **head);
int		ft_find_biggest(t_stack *list);
int		ft_find_lowest(t_stack *list);
int		adjacent_to_head_b(t_stack *head_a, t_stack *head_b, t_pos moves);
int		send_to_head_b(t_stack *head_a, t_stack *head_b, t_pos moves);
int		send_to_head_b_changes(t_stack *head_a, t_stack *head_b, t_pos moves);
int		send_to_head_b_nchanges(t_stack *head_a, t_stack *head_b, t_pos moves, int n);
int		send_to_head_b_relnchanges(t_stack *head_a, t_stack *head_b, t_pos moves, int n);
int		ft_last_in_list_pos(t_stack *list);
int		ft_2nlast_in_list_pos(t_stack *list);
t_pos	ft_index_adjacent_info(t_stack *head);
int		ft_find_lowest_5poses(t_stack *list);
int		ft_find_lowest_5poses_changes(t_stack *list);
int		ft_find_lowest_nposes_changes(t_stack *list, int n);
int		ft_find_lowest_relnposes_changes(t_stack *list, int n);
t_pos	ft_best_solution(t_stack *head_a, t_stack *head_b, t_pos moves, int n);
t_pos	ft_best_solution_back(t_stack *head_a, t_stack *head_b, t_pos moves);
t_pos	ft_find_lowest_relncmp(t_stack *list, t_pos moves, int n);
t_pos	send_to_head_b_relncmp(t_stack *head_a, t_stack *head_b, t_pos moves, int n);

/*more utils*/

/*print int array*/
void	ft_print_int_array(int *array, int amount);
int		ft_list_duplicates(t_stack *list);
t_stack	*ft_go_to_in_list(t_stack *list, int pos);

#endif