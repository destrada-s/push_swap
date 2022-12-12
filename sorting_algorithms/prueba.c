#include <stdio.h>
#include <stdlib.h>

typedef struct s_count
{
	int	i;
	int	j;
	int	k;
	int	middle;
}	t_count;

void	ft_merge_sort(int *array, int left_index, int right_index, t_count cnt);
void	ft_merge(int *array, int left_index, int middle,
			int right_index, t_count cnt);
void	merge(int arr[], int l, int m, int r);

void	ft_merge(int *array, int left_index, int middle, int right_index , t_count cnt)
{
	int	*left_half;
	int	*right_half;
	int	left_size;
	int	right_size;

	cnt.i = 0;
	cnt.j = 0;
	left_size = middle - left_index + 1;
	right_size = right_index - middle;
	left_half = (int *)(calloc(left_size, sizeof(int)));
	right_half = (int *)(calloc(right_size, sizeof(int)));
	while (cnt.i < left_size)
	{
		left_half[cnt.i] = array[left_index + cnt.i];
		cnt.i++;
	}
	while (cnt.j < right_size)
	{
		right_half[cnt.j] = array[middle + 1 + cnt.j];
		cnt.j++;
	}
	// Merge temporal arrays again
	cnt.i = 0;
	cnt.j = 0;
	cnt.k = left_index;
	while (cnt.i < left_size && cnt.j < right_size)
	{
		if (left_half[cnt.i] <= right_half[cnt.j])
		{
			array[cnt.k] = left_half[cnt.i];
			cnt.i++;
		}
		else
		{
			array[cnt.k] = right_half[cnt.j];
			cnt.j++;
		}
		cnt.k++;
	}
	while (cnt.i < left_size)
	{
		array[cnt.k] = left_half[cnt.i];
		cnt.i++;
		cnt.k++;
	}
	while (cnt.j < right_size)
	{
		array[cnt.k] = right_half[cnt.j];
		cnt.j++;
		cnt.k++;
	}
}

//Merge sort algorithm
void	ft_merge_sort(int *array, int left_index, int right_index, t_count cnt)
{
	if (left_index < right_index)
	{
		cnt.middle = left_index + (right_index - left_index) / 2;
		ft_merge_sort(array, left_index, cnt.middle, cnt);
		ft_merge_sort(array, cnt.middle + 1, right_index, cnt);

		ft_merge(array, left_index, cnt.middle, right_index, cnt);
	}
}

int main()
{
	int	array[] = {30,29,28,27, 39};
	int array_size;
	int i;
	t_count cnt;

	cnt.middle = 0;
	cnt.i = 0;
	cnt.j = 0;
	cnt.k = 1;
array_size = sizeof(array)/sizeof(int);
/*array Merge sorted*/
printf("Merge sort:\n");
int left_index = 0;
int right_index = array_size - 1;
	ft_merge_sort(array, left_index, right_index, cnt);
	i = 0;
	while (i < array_size)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
}