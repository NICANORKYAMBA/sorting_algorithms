#include "sort.h"

/**
 * selection_sort - sorts an array of integers using
 *	    selection sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 * Description: prints the sorted array after every pass
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}

/**
 * swap - swaps two integers in an array
 *
 * @x: first integer
 * @y: second integer
 * Return: Nothing
 */
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
