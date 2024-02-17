#include "sort.h"

/**
* quick_sort - Sorts an array of integers in ascending order
* using the Quick sort algorithm with Lomuto partition scheme
*
* @array: The array to be sorted
* @size: Number of elements in the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
* quick_sort_recursive - Recursive helper function for Quick Sort
*
* @array: The array to be sorted
* @low: The starting index of the partition
* @high: The ending index of the partition
* @size: Number of elements in the array
*/
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	/*checking if the subarray has more than one element*/
	if (low < high)
	{
		/* Perform partition and get the pivot index */
		int pivot_index = lomuto_partition(array, low, high, size);

		/* Recursively sort the subarrays on both sides of the pivot */
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
* lomuto_partition - Lomuto partition scheme for Quick Sort
*
* @array: The array to be partitioned
* @low: The starting index of the partition
* @high: The ending index of the partition
* @size: Number of elements in the array
*
* Return: The pivot index
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			/* Swap elements */
			if (i != j)
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;

				/* Print the array after each swap */
				print_array(array, size);
			}
		}
	}

	/* Swap the pivot into its correct position */
	if ((i + 1) != high)
	{
		int temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;

		/* Print the array after each swap */
		print_array(array, size);
	}

	return i + 1; /* Return the pivot index */
}
