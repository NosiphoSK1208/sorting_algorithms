#include "sort.h"

void blend_subarr(int *sb_arr, int *bff, size_t fore, size_t midd,
		size_t rear);
void blend_sort_recursive(int *sb_arr, int *bff, size_t fore, size_t rear);
void merge_sort(int *array, size_t size);

/**
 * blend_subarr - Sort a subarray of integers.
 * @sb_arr: A subarray of an array of integers to sort.
 * @bff: A buffer to store the sorted subarray.
 * @fore: A front index of the array.
 * @midd: A middle index of the array.
 * @rear: A rear index of the array.
 */
void blend_subarr(int *sb_arr, int *bff, size_t fore, size_t midd,
		size_t rear)
{
	size_t i, x, v = 0;

	printf("Merging...\n[left]: ");
	print_array(sb_arr + fore, midd - fore);

	printf("[right]: ");
	print_array(sb_arr + midd, rear - midd);

	for (i = fore, x = midd; i < midd && x < rear; v++)
		bff[v] = (sb_arr[i] < sb_arr[x]) ? sb_arr[i++] : sb_arr[x++];
	for (; i < midd; i++)
		bff[v++] = sb_arr[i];
	for (; x < rear; x++)
		bff[v++] = sb_arr[x];
	for (i = fore, v = 0; i < rear; i++)
		sb_arr[i] = bff[v++];

	printf("[Done]: ");
	print_array(sb_arr + fore, rear - fore);
}

/**
 * blend_sort_recursive - Implement the merge sort algorithm through recursion.
 * @sb_arr: A subarray of an array of integers to sort.
 * @bff: A buffer to store the sorted result.
 * @fore: A front index of the subarray.
 * @rear: A rear index of the subarray.
 */
void blend_sort_recursive(int *sb_arr, int *bff, size_t fore, size_t rear)
{
	size_t midd;

	if (rear - fore > 1)
	{
		midd = fore + (rear - fore) / 2;
		blend_sort_recursive(sb_arr, bff, fore, midd);
		blend_sort_recursive(sb_arr, bff, midd, rear);
		blend_subarr(sb_arr, bff, fore, midd, rear);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @arr_int: An array of integers.
 * @size: A size of the array.
 *
 * Description: Implements the top-DESCENDING merge sort algorithm.
 */
void merge_sort(int *arr_int, size_t size)
{
	int *bff;

	if (arr_int == NULL || size < 2)
		return;

	bff = malloc(sizeof(int) * size);
	if (bff == NULL)
		return;

	blend_sort_recursive(arr_int, bff, 0, size);

	free(bff);
}
