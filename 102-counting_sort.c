#include "sort.h"

int get_max(int *array, int size);

/**
 * counting_sort - sort an array of integers using counting
 *		    algorthm
 *
 * @array: array of integers
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *counting_array, *sorted_array;
	size_t i, max;

	if (!array || size < 2)
		return;

	sorted_array = malloc(sizeof(int) * size);

	if (!sorted_array)
		return;
	max = get_max(array, size);

	counting_array = malloc(sizeof(int) * (max + 1));
	if (!counting_array)
		return;

	for (i = 0; i < (max + 1); i++)
		counting_array[i] = 0;
	for (i = 0; i < size; i++)
		counting_array[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		counting_array[i] += counting_array[i - 1];
	print_array(counting_array, max + 1);

	for (i = 0; i < size; i++)
	{
		sorted_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];

	free(sorted_array);
	free(counting_array);
}

/**
 * get_max - get the maximum value in an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Return: maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}
