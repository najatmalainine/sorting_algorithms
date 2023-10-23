#include "sort.h"

/**
 *swap - swap 2 nodes in a doubly linked list
 *@array: array of integers to sort
 *@size: size of the array
 *@a: address of first value
 *@b: address of second value
 *Return: void
 */

void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array(array, size);
	}
}

/**
 *lomuto_partition - partitions the array
 *@array: array of integers to sort
 *@size: size of the array
 *@lo: the low index of the sort range
 *@hi: the high index of the sort range
 *Return: size_t
 */

size_t lomuto_partition(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	int i, j, pivot = array[hi];

	for (i = j = lo; j < hi; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[i++]);
	swap(array, size, &array[i], &array[hi]);

	return (i);
}


/**
 * quicksort - Quicksorts via Lomuto partinioning scheme
 *@array: array of integers to sort
 *@size: size of the array
 *@lo: the low index of the sort range
 *@hi: the high index of the sort range
 *Return: void
 */

void quicksort(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	if (lo < hi)
	{
		size_t p = lomuto_partition(array, size, lo, hi);

		quicksort(array, size, lo, p - 1);
		quicksort(array, size, p + 1, hi);
	}
}


/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: pointer to array
 * @size: size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);

}
