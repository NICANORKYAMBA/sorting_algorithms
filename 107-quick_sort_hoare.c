#include "sort.h"


void quicksort(int *array, int first, int last, size_t size);
int partition(int *array, int first, int last, size_t size);

/**
 * partition - array partition
 *
 * @array: array to sort
 * @first: first position
 * @last: last position
 * @size: array size
 * Return: pivot index
 */
int partition(int *array, int first, int last, size_t size)
{
	int pivot, i, j, tmp;

	pivot = array[last];
	i = first - 1;
	j = last + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (j < i)
			return (j);
		if (array[i] > array[j])
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
}

/**
 * quicksort - sorts an array of integers recursively
 * @array: array to sort
 * @first: first position
 * @last: last position
 * @size: array size
 */
void quicksort(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = partition(array, first, last, size);
		quicksort(array, first, pivot, size);
		quicksort(array, pivot + 1, last, size);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers using the Quick
 * sort hoare algorithm  in ascending order
 * @array: array to sort
 * @size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
