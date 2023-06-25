#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/* Direction comparison macros sort */
#define ASCENDING 0
#define DESCENDING 1

/**
 * struct listint_s - list node doubly linked
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * enum bool - Enumeration of Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/* The helper functions: printing  */
void print_array(const int *array, t_size size);
void print_list(const listint_t *list);

/* The algoritms sorting  */
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, t_size size);
void bubble_sort(int *array, t_size size);
void quick_sort(int *array, t_size size);
void shell_sort(int *array, t_size size);
void counting_sort(int *array, t_size size);
void merge_sort(int *array, t_size size);
void cocktail_sort_list(listint_t **list);
void heap_sort(int *array, t_size size);
void bitonic_sort(int *array, t_size size);
void radix_sort(int *array, t_size size);
void quick_sort_hoare(int *array, t_size size);

#endif /* The end of SORT_H */
