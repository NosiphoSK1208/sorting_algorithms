#include "sort.h"

int get_greatest(int *arr_int, int asz);
void a_counting_sort(int *arr_int, size_t asz, int sg, int *bff);
void radix_sort(int *arr_int, size_t asz);

/**
 * get_greatest - Get the maximum value in an array of integers.
 * @arr: an array of integers.
 * @asize: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_greatest(int *arr, int asize)
{
	int limit, k;

	for (limit = arr[0], k = 1; k < asize; k++)
	{
		if (arr[k] > limit)
			limit = arr[k];
	}

	return (limit);
}

/**
 * a_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @arr_int: an array of integers.
 * @asz: The asz of the array.
 * @sg: The significant digit to sort on.
 * @bff: A buffer to store the sorted arr_int.
 */
void a_counting_sort(int *arr_int, size_t asz, int sg, int *bff)
{
	int toll[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < asz; i++)
		toll[(arr_int[i] / sg) % 10] += 1;

	for (i = 0; i < 10; i++)
		toll[i] += toll[i - 1];

	for (i = asz - 1; (int)i >= 0; i--)
	{
		bff[toll[(arr_int[i] / sg) % 10] - 1] = arr_int[i];
		toll[(arr_int[i] / sg) % 10] -= 1;
	}

	for (i = 0; i < asz; i++)
		arr_int[i] = bff[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @arr_int: an array of integers.
 * @asz: The asz of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *arr_int, size_t asz)
{
	int lmt, sg, *bff;

	if (arr_int == NULL || asz < 2)
		return;

	bff = malloc(sizeof(int) * asz);
	if (bff == NULL)
		return;

	lmt = get_greatest(arr_int, asz);
	for (sg = 1; lmt / sg > 0; sg *= 10)
	{
		a_counting_sort(arr_int, asz, sg, bff);
		print_array(arr_int, asz);
	}

	free(bff);
}
