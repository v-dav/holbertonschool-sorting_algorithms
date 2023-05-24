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
int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int partition_index = start;
	int i;

	printf("Le pivot est %d et le partition index est %d\n", pivot, partition_index);

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swap(&array[i], &array[partition_index]);
			print_array(array, size);
			partition_index++;
		}
	}
	swap(&array[partition_index], &array[end]);
	print_array(array, size);
	return (partition_index);
}


void quick_sort(int *array, size_t size)
{
	if (!array)
		return;

	partition(array, 0, 4, size);

	/* base condition to stop the recursion: (if start >= end ->return)
	if start < end execute condition
	1 - Partition
	  - select pivot = array(size);
	  - partition_index = 0;
	  - scan array from 0 to size - 1: for (i = 0; i < size -1; i++)
	  - if < pivot -> push left : if  (array[i] <= pivot) -> swap array[i] et array[partition_index] ET partition_index +  1
	  après la boucle: swap (array[partition_index] et array[size])
	  -return partition_index

	2 - quick_sort left
	3 - quick_sort right */
}

int main(void)
{
	int array[] = {10, 5, 6, 1, 7};
	size_t n = 0;

	n = sizeof(array) / sizeof(int);

	print_array(array, n);
	quick_sort(array, n);

	return (0);
}
