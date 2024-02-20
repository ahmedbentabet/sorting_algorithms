#include "sort.h"

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, j;
	int k;

	while (gap < size)
	{
		gap = (gap * 3) + 1;
	}
	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		for (j = gap; j < size; j++)
		{
			for (k = j - gap; k >= 0; k -= gap)
			{
				if (array[k + gap] >= array[k])
					break;
				else
				{
					int temp;
					temp = array[k + gap];
					array[k + gap] = array[k];
					array[k] = temp;
				}
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
