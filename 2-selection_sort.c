#include "sort.h"
/**
 * selection_sort - implements the selection sort algorithm
 * to sort an array of integers in ascending order.
 *
 * @array: a pointer to the first element of the array to be sorted
 * @size: The size parameter is the number of elements in the array
 */

void selection_sort(int *array, size_t size)
{
	unsigned long int i = 0, j = 0, jMin = 0, tmp_i = 0;

	for (i = 0; i < size - 1; i++)
	{
		jMin = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[jMin])
			{
				jMin = j;
			}
		}

		if (jMin != i)
		{
			tmp_i = array[i];
			array[i] = array[jMin];
			array[jMin] = tmp_i;
			print_array(array, size);
		}
	}
}
