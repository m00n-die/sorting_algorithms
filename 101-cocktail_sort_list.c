#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap_next_node(listint_t **list, listint_t **end, listint_t **shaker);
void swap_prev_node(listint_t **list, listint_t **end, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_next_node - swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: pointer to the head of a doubly-linked list of integers.
 * @end: pointer to the tail of the doubly-linked list.
 * @shaker: pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_next_node(listint_t **list, listint_t **end, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*end = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_prev_node - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: pointer to the head of a doubly-linked list of integers.
 * @end: pointer to the tail of the doubly-linked list.
 * @shaker: pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_prev_node(listint_t **list, listint_t **end, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*end = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *end, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (end = *list; end->next != NULL;)
		end = end->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != end; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_next_node(list, &end, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_prev_node(list, &end, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
