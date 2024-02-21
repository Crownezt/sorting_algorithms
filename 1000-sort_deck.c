#include "deck.h"

int _strcmp(const char *s1, const char *s2);
char get_val(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_val(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - Compares two strings.
 * @s1: The 1st string to be compared.
 * @s2: The 2nd string to be compared.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_val - Get the numerical val of a card.
 * @card: A points to a deck_node_t card.
 *
 * Return: The numerical val of the card.
 */
char get_val(deck_node_t *card)
{
	if (_strcmp(card->card->val, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->val, "1") == 0)
		return (1);
	if (_strcmp(card->card->val, "2") == 0)
		return (2);
	if (_strcmp(card->card->val, "3") == 0)
		return (3);
	if (_strcmp(card->card->val, "4") == 0)
		return (4);
	if (_strcmp(card->card->val, "5") == 0)
		return (5);
	if (_strcmp(card->card->val, "6") == 0)
		return (6);
	if (_strcmp(card->card->val, "7") == 0)
		return (7);
	if (_strcmp(card->card->val, "8") == 0)
		return (8);
	if (_strcmp(card->card->val, "9") == 0)
		return (9);
	if (_strcmp(card->card->val, "10") == 0)
		return (10);
	if (_strcmp(card->card->val, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->val, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind - Sort a deck of cards from spades to diamonds.
 * @deck: A points to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *temp;

	for (iter = (*deck)->next; iter != NULL; iter = temp)
	{
		temp = iter->next;
		insert = iter->prev;
		while (insert != NULL && insert->card->kind > iter->card->kind)
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * insertion_sort_deck_val - Sort a deck of cards _sorted from
 *                             spades to diamonds from ace to king.
 * @deck: A points to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_val(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *temp;

	for (iter = (*deck)->next; iter != NULL; iter = temp)
	{
		temp = iter->next;
		insert = iter->prev;
		while (insert != NULL &&
		       insert->card->kind == iter->card->kind &&
		       get_val(insert) > get_val(iter))
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king also
 *             from spades to diamonds.
 * @deck: A points to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_val(deck);
}
