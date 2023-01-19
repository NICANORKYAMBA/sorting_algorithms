#include "sort.h"

/**
 * insertion_sort_list - sorts doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: head pointer of a doubly-linked list of integers.
 *
 * Description: prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	for (i = (*list)->next; i != NULL; i = tmp)
	{
		tmp = i->next;
		insert = i->prev;
		while (insert != NULL && i->n < insert->n)
		{
			swapnodes(list, &insert, i);
			print_list(*list);
		}
	}

}

/**
 * swapnodes - Swap two nodes in a listint_t doubly-linked list.
 *
 * @head: pointer to head of the doubly-linked list.
 * @node1: pointer to first node to swap.
 * @node2: second node to swap.
 * Returns: Nothing
 */
void swapnodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
	{
		node2->next->prev = *node1;
	}
	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}
