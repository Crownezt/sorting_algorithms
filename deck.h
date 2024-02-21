#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - Enumeration of the card _suits
 * @SPADE: Spades _suit
 * @HEART: Hearts _suit
 * @CLUB: Clubs _suit.
 * @DIAMOND: Diamonds _suit.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @val: val of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *val;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: points to the card of the node
 * @prev: points to the previous node of the list
 * @next: points to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
