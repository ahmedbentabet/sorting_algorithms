#include "sort.h"

/**
 * bubble_sort - sorts an array of integers
 * in ascending order using the Bubble sort
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;
	int temp;

	if (array == NULL || size < 2)
		return;

	/*Outer loop for the number of passes*/
	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		/*Inner loop for each pass, compares and swaps adjacent elements*/
		for (j = 0; j < size - i - 1; j++)
		{
			/*Compare adjacent elements*/
			if (array[j] > array[j + 1])
			{
				/*Swap elements*/
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/* Set the flag to true as a swap was made */
				swapped = 1;
				print_array(array, size);
			}
		}
		/* If no swaps were made during a pass, the array is already sorted */
		if (swapped == 0)
			break;
	}
}
