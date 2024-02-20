#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm with the Knuth sequence.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1; /* Initialize the gap with 1 */
	size_t u;       /* Index variable for iterating through the unsorted part */
	int s;          /* Index variable for iterating through the sorted part */
	int key;        /* Variable to store the current element for comparison */

	/* Calculate the initial gap using the Knuth sequence */
	while (gap < size)
	{
		gap = (gap * 3) + 1;
	}
	gap = (gap - 1) / 3;

	/* Continue sorting until the gap is greater than 0 */
	while (gap > 0)
	{
		u = gap; /* Initialize u with the gap size */

		/* Iterate through the array with the current gap */
		while (u < size)
		{
			key = array[u];
			s = u - gap;

			/* Compare and swap elements until in the correct order */
			while (s >= 0 && array[s] > key)
			{
				array[s + gap] = array[s];
				s = s - gap;
			}
			array[s + gap] = key;

			u = u + 1; /* Move to the next element in the unsorted part */
		}

		gap = (gap - 1) / 3; /* Update the gap using the Knuth sequence */
		print_array(array, size); /* Print the array after each iteration */
	}
}
