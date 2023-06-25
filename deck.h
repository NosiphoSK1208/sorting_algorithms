#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * enum kind_e - Enum of card suits.
 * @SPADE: Spades suit.
 * @CLUB: Clubs suit.
 * @DIAMOND: Diamonds suit.
 * @HEART: Hearts suit.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;



/**
 * struct deck_node_s - Node Deck of card
 *
 * @card: Index to the card of the node
 * @next: Index to the next node of the list
 * @prev: Index to the previous node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* The end of  DECK_H filw */
