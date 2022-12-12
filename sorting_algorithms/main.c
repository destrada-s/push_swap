/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: destrada <destrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:12:38 by destrada          #+#    #+#             */
/*   Updated: 2022/11/29 17:28:29 by destrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	ft_leaks(void)
{
	system("leaks sorting");
}

int main()
{
	int	array2[] = {30,29,28,27, 39, 43, 21};
	int array_size;
	int i;

atexit(ft_leaks);
	array_size = sizeof(array2) / sizeof(array2[0]);
	ft_printf("Array size: %d\n", array_size);
	for(i = 0; i < array_size; i++)
		ft_printf("%d ",array2[i]);
	ft_printf("\n");
/*array sorted*/
/*array Merge sorted*/
ft_printf("Merge sort:\n");
int left_index = 0;
int right_index = array_size - 1;
	ft_merge_sort(array2, left_index, right_index);
	i = 0;
	while (i < array_size)
	{
		ft_printf("%d ", array2[i]);
		i++;
	}
	ft_printf("\n");
}
