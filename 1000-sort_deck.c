#include "deck.h"

int comp_str(const char *first, const char *second);
char accept_urg(deck_node_t *ponter_c);
void insert_sdk(deck_node_t **dck);
void insertion_sdk_value(deck_node_t **dck);
void sort_deck(deck_node_t **dck);

/**
 * comp_str - Compares two strings.
 * @first: The first string to be compared.
 * @second: The second string to be compared.
 *
 * Return: Positive byte difference if first > second
 *         0 if first == second
 *         Negative byte difference if first < second
 */
int comp_str(const char *first, const char *second)
{
	while (*first && *second && *first == *second)
	{
		first++;
		second++;
	}

	if (*first != *second)
		return (*first - *second);
	return (0);
}

/**
 * accept_urg - Get the numerical value of a ponter_c.
 * @ponter_c: A pointer to a deck_node_t ponter_c.
 *
 * Return: The numerical value of the ponter_c.
 */
char accept_urg(deck_node_t *ponter_c)
{
	if (comp_str(ponter_c->ponter_c->value, "Ace") == 0)
		return (0);
	if (comp_str(ponter_c->ponter_c->value, "1") == 0)
		return (1);
	if (comp_str(ponter_c->ponter_c->value, "2") == 0)
		return (2);
	if (comp_str(ponter_c->ponter_c->value, "3") == 0)
		return (3);
	if (comp_str(ponter_c->ponter_c->value, "4") == 0)
		return (4);
	if (comp_str(ponter_c->ponter_c->value, "5") == 0)
		return (5);
	if (comp_str(ponter_c->ponter_c->value, "6") == 0)
		return (6);
	if (comp_str(ponter_c->ponter_c->value, "7") == 0)
		return (7);
	if (comp_str(ponter_c->ponter_c->value, "8") == 0)
		return (8);
	if (comp_str(ponter_c->ponter_c->value, "9") == 0)
		return (9);
	if (comp_str(ponter_c->ponter_c->value, "10") == 0)
		return (10);
	if (comp_str(ponter_c->ponter_c->value, "Jack") == 0)
		return (11);
	if (comp_str(ponter_c->ponter_c->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insert_sdk - Sort a dck of cards from spades to diamonds.
 * @dck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insert_sdk(deck_node_t **dck)
{
	deck_node_t *iter, *insrt, *holder;

	for (iter = (*dck)->next; iter != NULL; iter = holder)
	{
		holder = iter->next;
		insrt = iter->prev;
		while (insrt != NULL && insrt->ponter_c->kind > iter->ponter_c->kind)
		{
			insrt->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insrt;
			iter->prev = insrt->prev;
			iter->next = insrt;
			if (insrt->prev != NULL)
				insrt->prev->next = iter;
			else
				*dck = iter;
			insrt->prev = iter;
			insrt = iter->prev;
		}
	}
}

/**
 * insertion_sdk_value - Sort a dck of cards sorted from
 *                             spades to diamonds from ace to king.
 * @dck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sdk_value(deck_node_t **dck)
{
	deck_node_t *iter, *insrt, *holder;

	for (iter = (*dck)->next; iter != NULL; iter = holder)
	{
		holder = iter->next;
		insrt = iter->prev;
		while (insrt != NULL &&
		       insrt->ponter_c->kind == iter->ponter_c->kind &&
		       accept_urg(insrt) > accept_urg(iter))
		{
			insrt->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insrt;
			iter->prev = insrt->prev;
			iter->next = insrt;
			if (insrt->prev != NULL)
				insrt->prev->next = iter;
			else
				*dck = iter;
			insrt->prev = iter;
			insrt = iter->prev;
		}
	}
}

/**
 * sort_deck - Sort a dck of cards from ace to king and
 *             from spades to diamonds.
 * @dck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **dck)
{
	if (dck == NULL || *dck == NULL || (*dck)->next == NULL)
		return;

	insert_sdk(dck);
	insertion_sdk_value(dck);
}
