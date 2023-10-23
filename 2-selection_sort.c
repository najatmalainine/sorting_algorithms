#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: pointer to array
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	int temp, flag = 0;
	size_t i, j, min_idx;

	if (!array || !size)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		flag = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
				flag += 1;
			}
		}
		temp = array[i];
		array[i] = array[min_idx];
		array[min_idx] = temp;
		if (flag != 0)
			print_array(array, size);
	}

}
