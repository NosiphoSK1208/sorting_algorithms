#include "sort.h"

/**
 * exchange_ints - Swap two integers in an array.
 * @first: The first integer to swap.
 * @second: The second integer to swap.
 */
void exchange_ints(int *first, int *second)
{
	int impermanent;

	impermanent = *first;
	*first = *second;
	*second = impermanent;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @arr_int: Array of integers.
 * @asize: Size of the array.
 *
 * Description: Uses Knuth interval sequence.
 */
void shell_sort(int *arr_int, size_t asize)
{
	size_t gp, i, k;

	if (arr_int == NULL || asize < 2)
		return;

	for (gp = 1; gp < (asize / 3);)
		gp = gp * 3 + 1;

	for (; gp >= 1; gp /= 3)
	{
		for (i = gp; i < asize; i++)
		{
			k = i;
			while (k >= gp && arr_int[k - gp] > arr_int[k])
			{
				exchange_ints(arr_int + k, arr_int + (k - gp));
				k -= gp;
			}
		}
		print_array(arr_int, asize);
	}
}
