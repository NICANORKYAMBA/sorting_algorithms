#include "sort.h"

/**
 * quick_sort - sort an array using the quick sort algorithm.
 *
 * @array: an array of integers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size == 0)
	{
		return;
	}
	partition(array, size, 0, size - 1);
}

/**
 * quicksortswap - swaps 2 elements of a given array.
 *
 * @array: an array of integers
 * @size: size of the array.
 * @index: index of position within the array
 * @wall: index of position within the array
 */
void quicksortswap(int *array, size_t size, int index, int wall)
{
	int tmp;

	tmp = array[wall];

	if (index != wall)
	{
		array[wall] = array[index];
		array[index] = tmp;
		print_array(array, size);
	}
}

/**
 * partition - sort a partition of an array
 *
 * @array: array to be partitioned and sorted
 * @size: size of the array
 * @low: beginning of a partition. (left side)
 * @high: end of a partition. (right side)
 */
void partition(int *array, size_t size, int low, int high)
{
	int i, pivot, wall;

	if ((high) - low <= 0)
		return;
	if (high == 1 && array[0] < array[high])
		return;

	i = wall = low;
	pivot = high;
	while (i < pivot)
	{
		if (array[i] < array[pivot])
		{
			quicksortswap(array, size, i, wall);
			wall++;
		}
		i++;
	}
	quicksortswap(array, size, pivot, wall);

	if (high - low > 0)
		partition(array, size, wall + 1, high);
	if (high - low > 0)
		partition(array, size, low, wall - 1);
}
