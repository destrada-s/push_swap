/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:09:52 by destrada          #+#    #+#             */
/*   Updated: 2022/11/29 15:08:36 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mega_libft/libft.h"
#include "sort.h"

void	ft_int_swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

/*If want to check amount of moves done insert nb_checks in the condition
Same as normal bubble sort in any scenario 
Worst case sceneario is Summatory so if 5 = 4 + 3 + 2 + 1 */

/*
selection sort algorithm sorts by looking to see if the min is i if after 
second loop its not i it swaps it with the new min ->  this algorithm is a mix 
between the selection where puts the lesser in i and bubble as it does
the swap everytime so it is worst as does more swaps than needed
*/
void	ft_sort_int_array(int *array, int size)
{
	int	i;
	int	j;
	int	nb_checks;

	i = 0;
	nb_checks = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				ft_int_swap(&array[i], &array[j]);	
			}
			j++;
			nb_checks++;
		}
	i++;
	}
}

void	ft_selection_sort(int *array, int size)
{
	int	min_idx;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (array[min_idx] > array[j])
				min_idx = j;
			j++;
		}
		if (min_idx != i)
			ft_int_swap(&array[i], &array[min_idx]);
		i++;
	}
}

void	ft_bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	nb_checks;

	i = 0;
	nb_checks = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (array[j] > array[j + 1])
			{
				ft_int_swap(&array[j], &array[j + 1]);
			}
			j++;
			nb_checks++;
		}
		i++;
	}
}
/* Better Bubble as if in an iteration it does not do a swap it means it is 
totally sorted so it stops with a flag */
void	ft_better_bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	nb_checks;
	int	flag;

	flag = -1;
	i = 0;
	nb_checks = 0;
	while (i < size - 1 && flag != 0)
	{
		flag = 0;
		j = 0;
		while (j < size - 1 - i)
		{
			if (array[j] > array[j + 1])
			{
				ft_int_swap(&array[j], &array[j + 1]);
				flag = 1;
			}
			j++;
			nb_checks++;
		}
		i++;
	}
	ft_printf("amount of checks %d\n", nb_checks);
}

// void	ft_merge(int *array, int left_index, t_count cnt, int right_index)
// {
// 	t_arrays	sides;

// 	cnt.i = 0;
// 	cnt.j = 0;
// 	sides.left_half = (int *)(ft_calloc(cnt.left_size, sizeof(int)));
// 	sides.right_half = (int *)(ft_calloc(cnt.right_size, sizeof(int)));
// 	cnt.left_size = cnt.middle - left_index + 1;
// 	cnt.right_size = right_index - cnt.middle;
// 	while (cnt.i < cnt.left_size)
// 	{
// 		sides.left_half[cnt.i] = array[left_index + cnt.i];
// 		cnt.i++;
// 	}
// 	while (cnt.j < cnt.right_size)
// 	{
// 		sides.right_half[cnt.j] = array[cnt.middle + 1 + cnt.j];
// 		cnt.j++;
// 	}	
// 	cnt.i = 0;
// 	cnt.j = 0;
// 	cnt.k = left_index;
// 	while (cnt.i < cnt.left_size && cnt.j < cnt.right_size)
// 	{
// 		if (sides.left_half[cnt.i] < sides.right_half[cnt.j])
// 		{
// 			array[cnt.k] = sides.left_half[cnt.i];
// 			cnt.i++;
// 		}
// 		else
// 		{
// 			array[cnt.k] = sides.right_half[cnt.j];
// 			cnt.j++;
// 		}
// 		cnt.k++;
// 	}
// 	while (cnt.i < cnt.left_size)
// 	{
// 		array[cnt.k] = sides.left_half[cnt.i];
// 		cnt.i++;
// 		cnt.k++;
// 	}
// 	while (cnt.j < cnt.right_size)
// 	{
// 		array[cnt.k] = sides.right_half[cnt.j];
// 		cnt.j++;
// 		cnt.k++;
// 	}	
// 	free(sides.left_half);
// 	free(sides.right_half);
// }

