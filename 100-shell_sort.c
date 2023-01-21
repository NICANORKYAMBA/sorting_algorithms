#include "sort.h"

/**
 * shell_sort - sorts an array of integers using shell sort
 *		algorithm
 * @array: the array of integers to sort
 * @size: length of the array
 * Description: prints a sorted array of integers
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int k;

	if (!array || size < 2)
	{
		return;
	}

	gap = 1;

	while (gap < size / 3)
	{
		gap = (gap * 3) + 1;
	}

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			k = array[i];
			j = i;

			while (j > gap - 1 && array[j - gap] >= k)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
			array[j] = k;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
