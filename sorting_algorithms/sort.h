/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:38:52 by destrada          #+#    #+#             */
/*   Updated: 2022/11/29 17:08:31 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
# include "../mega_libft/libft.h"

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

void	ft_int_swap(int *a, int *b);
void	ft_sort_int_array(int *array, int array_size);
void	ft_bubble_sort(int *array, int size);
void	ft_better_bubble_sort(int *array, int size);
void	ft_selection_sort(int *array, int size);
void	ft_insertion_sort(int *array, int size);
void	ft_merge(int *array, int left_index, t_count cnt, int right_index);
void	ft_merge_sort(int *array, int left_index, int right_index);

#endif 