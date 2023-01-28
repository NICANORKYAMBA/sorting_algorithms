#include "sort.h"

int getmax(int *array, size_t size);
void countingsort(int *array, size_t size, size_t place);

/**
 * radix_sort - sorts an array of integers by applying
 *		radix sort algorithm
 *
 * @array: array of integers to sort
 * @size: size of the array
 * Description: prints a sorted array of integers
 */
void radix_sort(int *array, size_t size)
{
	int max, place;

	max = getmax(array, size);

	for (place = 1; max / place > 0; place *= 10)
	{
		countingsort(array, size, place);
		print_array(array, size);
	}
}

/**
 * getmax - determines maximum number in an array
 *
 * @array: array of integers
 * @size: size of the array
 * Return: maximum number in an array
 */
int getmax(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countingsort - sorts an array of integers by applying
 *		    counting sort algorithm
 *
 * @array: array of integers
 * @size: size of the array
 * @place: significant digit to sort
 */
void countingsort(int *array, size_t size, size_t place)
{
	int *output;
	size_t i;
	int count[10] = {0};

	for (i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	output = malloc(sizeof(int) * size);

	if (!output)
		return;

	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}
