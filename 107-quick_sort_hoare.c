#include "sort.h"

void swap_ints(int *a, int *b);
void hoare_sort(int *array, size_t size, int left, int right);
int partition(int *array, size_t size, int left, int right);

/**
 * swap_ints - Swap two integers in an array.
 * @a: first integer to swap.
 * @b: second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - array partition
 *
 * @array: array to sort
 * @size: size of the array
 * @left: first position
 * @right: last position
 * Return: pivot index
 */
int partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - implement the quicksort algorithm through recursion.
 * @array: array of integers to sort.
 * @size: size of the array.
 * @left: first index of the array partition to order.
 * @right: last index of the array partition to order.
 *
 * Description: uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
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
	hoare_sort(array, size, 0, size - 1);
}
