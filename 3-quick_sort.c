#include "sort.h"
/**
 * swap - function that swaps two integers in an array
 * and prints the updated array
 *
 * @a:  pointer to an integer variable that will be swapped
 * with another integer variable.
 * @b: pointer to an integer. It is used in the function to swap the value
 * it points to with the value pointed to by another integer pointer "a"
 * @array: an array of integers
 * @size: The parameter "size" is of type "size_t" and represents the size
 * of the array that is being passed as a parameter to the function.
 */
void swap(int *a, int *b, int *array, size_t size)
{
	int temp;

	if (*a != *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
		print_array(array, size);
	}
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

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swap(&array[i], &array[partition_index], array, size);
			partition_index++;
		}
	}
	swap(&array[partition_index], &array[end], array, size);
	return (partition_index);
}

/**
 * quick_sort_helper - a helper function for quick sort algorithm
 * that recursively sorts an integer array.
 *
 * @array: A pointer to the first element of the array to be sorted.
 * @start: The index of the first element in the subarray being sorted
 * @end: represents the index of the last element in the subarray
 * @original_size: the size of the original array that is being sorted.
 */
void quick_sort_helper(int *array, int start, int end, size_t original_size)
{
	int partition_index;

	if (start < end)
	{
		partition_index = partition(array, start, end, original_size);

		quick_sort_helper(array, start, partition_index - 1, original_size);
		quick_sort_helper(array, partition_index + 1, end, original_size);
	}
}

/**
 * quick_sort - This function calls a helper function
 * to perform quick sort on an array
 *
 * @array: A pointer to the first element of the array to be sorted
 * @size: The size parameter represents the number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1, size);
}
