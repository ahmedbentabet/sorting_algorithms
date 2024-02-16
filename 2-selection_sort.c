#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp;

	/* Check edge cases */
	if (array == NULL || size < 2)
		return;

	/* Iterate through the array */
	for (i = 0; i < size - 1; i++)
	{
		/* Assume the current index has the minimum value */
		min_index = i;

		/* Find the index of the minimum element in the unsorted portion */
		for (j = i + 1; j < size; j++)
		{
			/* Update min_index if a smaller element is found */
			if (array[j] < array[min_index])
				min_index = j;
		}

		/* Check if a swap is needed */
		if (min_index != i)
		{
			/* Swap elns to move the minimum element to its correct position */
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;

			/* Print the array after each swap */
			print_array(array, size);
		}
	}
}
