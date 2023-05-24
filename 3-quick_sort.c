#include "sort.h"

/**
 * swap - swaps the values of two integers
 * @a: a pointer to 1st int
 * @b: a pointer to 2nd int
 *
 * Return: nothing
 */
void swap (int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - The function partitions an array by selecting a pivot and
 * rearranging the elements such that all elements smaller than the pivot
 * are on one side and all elements larger than the pivot are on the other side
 *
 * @array: A pointer to the array that needs to be partitioned.
 * @start: The starting index of the subarray being partitioned.
 * @end: The "end" parameter in the "partition" function is an integer that
 * represents the index of the last element in the array that needs
 * to be partitioned.
 * @size: The size parameter is the size of the array being sorted. 
 * It is used to ensure that the print_array function prints the correct 
 * number of elements.
 *
 * Return: the partition index, which is the index where the pivot element
 * is placed after the partitioning process.
 */
int partition(int *array, int start, int end)
{
	int pivot = array[end];
	int partition_index = start;
	int i, n;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swap(&array[i], &array[partition_index]);
			print_array(array, n);
			partition_index++;
		}
	}
	swap(&array[partition_index], &array[end]);
	return (partition_index);
}

void quick_sort(int *array, size_t size)
{
	int start = 0;
	int end = size - 1;
	int partition_index;

	if (!array)
		return;

	if (start < end)
	{
		
		partition_index = partition(array, start, end);

		quick_sort(array, partition_index);
		quick_sort(array + partition_index + 1, end - partition_index);
	} 
}

