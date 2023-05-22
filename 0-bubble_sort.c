#include "sort.h"

/**
 * bubble_sort - implements the bubble sort algorithm to sort
 * an array of integers in ascending order.
 *
 * @array: a pointer to the first element of the array to be sorted
 * @size: The parameter "size" is of type "size_t" and represents the number
 * of elements in the array that needs to be sorted.
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long int i = 0;
	unsigned long int tmp = 0;
	int swap = 1;

	while (swap)
	{
		swap = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = tmp;
				print_array(array, size);
				swap = 1;
			}
		}
	}
}
