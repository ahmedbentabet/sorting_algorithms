#include "sort.h"

/**
 * my_swap - Swaps the values of two integers
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void my_swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
