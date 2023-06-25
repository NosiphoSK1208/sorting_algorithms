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
 * selection_sort - Sort an array of integers in ascending order.
 * @ints_arr: Array of integers.
 * @sze: Size of the array.
 *
 * Description: Prints the ints_arr after each swap.
 */
void selection_sort(int *ints_arr, size_t sze)
{
	int *bas;
	size_t i, k;

	if (ints_arr == NULL || sze < 2)
		return;

	for (i = 0; i < sze - 1; i++)
	{
		bas = ints_arr + i;
		for (k = i + 1; k < sze; k++)
			bas = (ints_arr[k] < *bas) ? (ints_arr + k) : bas;

		if ((ints_arr + i) != bas)
		{
			exchange_ints(ints_arr + i, bas);
			print_array(ints_arr, sze);
		}
	}
}
