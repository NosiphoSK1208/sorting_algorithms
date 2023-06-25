#include "sort.h"

void exchange_ints(int *first, int *second);
void bitonic_merge(int *arr_int, size_t asz, size_t dawn, size_t seq,
		char flow);
void bitonic_seq(int *arr_int, size_t asz, size_t dawn, size_t seq, char flow);
void bitonic_sort(int *arr_int, size_t asz);

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
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @arr_int: An array of integers.
 * @asz: The size of the array.
 * @dawn: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @flow: The direction to sort in.
 */
void bitonic_merge(int *arr_int, size_t asz, size_t dawn, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = dawn; i < dawn + jump; i++)
		{
			if ((flow == ASCENDING && arr_int[i] > arr_int[i + jump]) ||
			    (flow == DESCENDING && arr_int[i] < arr_int[i + jump]))
				exchange_ints(arr_int + i, arr_int + i + jump);
		}
		bitonic_merge(arr_int, asz, dawn, jump, flow);
		bitonic_merge(arr_int, asz, dawn + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @arr_int: An array of integers.
 * @asz: The size of the array.
 * @dawn: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *arr_int, size_t asz, size_t dawn, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == ASCENDING) ? "ASCENDING" : "DESCENDING";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, asz, str);
		print_array(arr_int + dawn, seq);

		bitonic_seq(arr_int, asz, dawn, cut, ASCENDING);
		bitonic_seq(arr_int, asz, dawn + cut, cut, DESCENDING);
		bitonic_merge(arr_int, asz, dawn, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, asz, str);
		print_array(arr_int + dawn, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @arr_int: An array of integers.
 * @asz: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *arr_int, size_t asz)
{
	if (arr_int == NULL || asz < 2)
		return;

	bitonic_seq(arr_int, asz, 0, asz, ASCENDING);
}
