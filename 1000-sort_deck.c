#include "deck.h"

int str_cmp(const char *st1, const char *st2);
char get_myvalue(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * str_cmp - Compares two strings.
 * @st1: The first string to be compared.
 * @st2: The second string to be compared.
 *
 * Return: Positive byte difference if st1 > st2
 *         0 if st1 == st2
 *         Negative byte difference if st1 < st2
 */
int str_cmp(const char *st1, const char *st2)
{
	while (*st1 && *st2 && *st1 == *st2)
	{
		st1++;
		st2++;
	}

	if (*st1 != *st2)
		return (*st1 - *st2);
	return (0);
}

/**
 * get_myvalue - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char get_myvalue(deck_node_t *card)
{
	if (str_cmp(card->card->value, "Ace") == 0)
		return (0);
	if (str_cmp(card->card->value, "1") == 0)
		return (1);
	if (str_cmp(card->card->value, "2") == 0)
		return (2);
	if (str_cmp(card->card->value, "3") == 0)
		return (3);
	if (str_cmp(card->card->value, "4") == 0)
		return (4);
	if (str_cmp(card->card->value, "5") == 0)
		return (5);
	if (str_cmp(card->card->value, "6") == 0)
		return (6);
	if (str_cmp(card->card->value, "7") == 0)
		return (7);
	if (str_cmp(card->card->value, "8") == 0)
		return (8);
	if (str_cmp(card->card->value, "9") == 0)
		return (9);
	if (str_cmp(card->card->value, "10") == 0)
		return (10);
	if (str_cmp(card->card->value, "Jack") == 0)
		return (11);
	if (str_cmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind - Sort a deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
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
 * insertion_sort_deck_value - Sort a deck of cards sorted from
 *                             spades to diamonds from ace to king.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL &&
		       insert->card->kind == iter->card->kind &&
		       get_myvalue(insert) > get_myvalue(iter))
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
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
