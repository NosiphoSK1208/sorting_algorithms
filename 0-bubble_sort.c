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
 * bubble_sort - Sort an array of integers in ascending order.
 * @int_arr: Array of integers to be sort.
 * @asize: Size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *int_arr, size_t asize)
{
	size_t i, dur = asize;
	bool cava = false;

	if (int_arr == NULL || asize < 2)
		return;

	while (cava == false)
	{
		cava = true;
		for (i = 0; i < dur - 1; i++)
		{
			if (int_arr[i] > int_arr[i + 1])
			{
				exchange_ints(int_arr + i, int_arr + i + 1);
				print_array(int_arr, asize);
				cava = false;
			}
		}
		dur--;
	}
}
