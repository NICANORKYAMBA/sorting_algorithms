#include "sort.h"

void heapify(int *array, size_t size, size_t base, size_t i);
void swap(int *a, int *b);

/**
 * heap_sort - sorts an array using heap_sort algorithm
 *
 * @array: array of integers to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
	{
		return;
	}
	for (i = (size / 2) - 1; i >= 0; i--)
	{
		heapify(array, size, size, i);
	}
	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);

		heapify(array, size, i, 0);
	}
}

/**
 * heapify - turns a binary tree into a complete binary heap.
 *
 * @array: an array of integers representing a binary tree.
 * @size: size of the array/tree.
 * @base: index of the base row of the tree.
 * @i: root node of the binary tree.
 */
void heapify(int *array, size_t size, size_t base, size_t i)
{
	size_t largest, left, right;

	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < base && array[left] > array[largest])
	{
		largest = left;
	}
	if (right < base && array[right] > array[largest])
	{
		largest = right;
	}
	if (largest != i)
	{
		swap(array + i, array + largest);
		print_array(array, size);

		heapify(array, size, base, largest);
	}
}

/**
 * swap - swaps two integers
 *
 * @a: first integer to swap
 * @b: second integer to swap
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
