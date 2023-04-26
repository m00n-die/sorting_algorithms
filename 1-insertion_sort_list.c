#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swap two nodes in a listint_t doubly-linked list.
 * 
 * @head: pointer to the head of the doubly-linked list.
 * 
 * @node1: pointer to the first node to swap.
 * 
 * @node2: second node to swap.
 */

void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *                          in ascending order using the Insertion sort algorithm
 * 
 * @list: a pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = temp)
	{
		temp = i->next;
		insert = i->prev;
		while (insert != NULL && i->n < insert->n)
		{
			swap_nodes(list, &insert, i);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}
