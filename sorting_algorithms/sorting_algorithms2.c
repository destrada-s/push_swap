/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:43:41 by destrada          #+#    #+#             */
/*   Updated: 2022/11/29 18:13:02 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	ft_insertion_sort(int *array, int size)
{
	int	key;
	int	i;
	int	j;
	int	num;

	i = 1;
	num = 0;
	while (i < size)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && key < array[j])
		{
			ft_int_swap(&array[j + 1], &array[j]);
			j--;
			num++;
		}
		array[j + 1] = key;
		i++;
		num++;
	}
}

t_count	ft_creat_arrays(int *array, t_count cnt, int left_index,
		int right_index)
{
	cnt.i = 0;
	cnt.j = 0;
	cnt.left_size = cnt.middle - left_index + 1;
	cnt.right_size = right_index - cnt.middle;
	cnt.left_half = (int *)(ft_calloc(cnt.left_size, sizeof(int)));
	cnt.right_half = (int *)(ft_calloc(cnt.right_size, sizeof(int)));
	while (cnt.i < cnt.left_size)
	{
		cnt.left_half[cnt.i] = array[left_index + cnt.i];
		cnt.i++;
	}
	while (cnt.j < cnt.right_size)
	{
		cnt.right_half[cnt.j] = array[cnt.middle + 1 + cnt.j];
		cnt.j++;
	}
	return (cnt);
}

void	sort_halfof_merge(int *array, t_count *cnt)
{
	while (cnt->i < cnt->left_size && cnt->j < cnt->right_size)
	{
		if (cnt->left_half[cnt->i] < cnt->right_half[cnt->j])
		{
			array[cnt->k] = cnt->left_half[cnt->i];
			cnt->i++;
		}
		else
		{
			array[cnt->k] = cnt->right_half[cnt->j];
			cnt->j++;
		}
		cnt->k++;
	}
}

void	ft_merge(int *array, int left_index, t_count cnt, int right_index)
{
	cnt = ft_creat_arrays(array, cnt, left_index, right_index);
	cnt.i = 0;
	cnt.j = 0;
	cnt.k = left_index;
	sort_halfof_merge(array, &cnt);
	while (cnt.i < cnt.left_size)
	{
		array[cnt.k] = cnt.left_half[cnt.i];
		cnt.i++;
		cnt.k++;
	}
	while (cnt.j < cnt.right_size)
	{
		array[cnt.k] = cnt.right_half[cnt.j];
		cnt.j++;
		cnt.k++;
	}
	free(cnt.right_half);
	free(cnt.left_half);
}

void	ft_merge_sort(int *array, int left_index, int right_index)
{
	t_count	cnt;

	cnt.middle = 0;
	if (right_index > left_index)
	{
		cnt.middle = left_index + (right_index - left_index) / 2;
		ft_merge_sort(array, left_index, cnt.middle);
		ft_merge_sort(array, cnt.middle + 1, right_index);
		ft_merge(array, left_index, cnt, right_index);
	}
}
