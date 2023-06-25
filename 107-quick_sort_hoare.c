#include "sort.h"

void exchange_ints(int *first, int *second);
int hoare_partition(int *arr_in, size_t asz, int left, int right);
void hoare_sort(int *arr_in, size_t asz, int left, int right);
void quick_sort_hoare(int *arr_in, size_t asz);

/**
 * exchange_ints - Swap two integers in an arr_in.
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
 * hoare_partition - Order a subset of an arr_in of integers
 *                   according to the hoare partition scheme.
 * @arr_in: The arr_in of integers.
 * @asz: The asz of the arr_in.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the arr_in after each swap of two elements.
 */
int hoare_partition(int *arr_in, size_t asz, int left, int right)
{
	int pivot, above, below;

	pivot = arr_in[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (arr_in[above] < pivot);
		do {
			below--;
		} while (arr_in[below] > pivot);

		if (above < below)
		{
			exchange_ints(arr_in + above, arr_in + below);
			print_array(arr_in, asz);
		}
	}

	return (above);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @arr_in: An arr_in of integers to sort.
 * @asz: The asz of the arr_in.
 * @left: The starting index of the arr_in partition to order.
 * @right: The ending index of the arr_in partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *arr_in, size_t asz, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(arr_in, asz, left, right);
		hoare_sort(arr_in, asz, left, part - 1);
		hoare_sort(arr_in, asz, part, right);
	}
}

/**
 * quick_sort_hoare - Sort an arr_in of integers in ascending
 *                    order using the quicksort algorithm.
 * @arr_in: An arr_in of integers.
 * @asz: The asz of the arr_in.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the arr_in after each swap of two elements.
 */
void quick_sort_hoare(int *arr_in, size_t asz)
{
	if (arr_in == NULL || asz < 2)
		return;

	hoare_sort(arr_in, asz, 0, asz - 1);
}
