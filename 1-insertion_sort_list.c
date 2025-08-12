#include "sort.h"

/**
 * swap_with_prev - Swap `node` with its previous node in a doubly linked list
 * @list: the pointer to the list to sawp
 * @node: the pointer to the node
 *
 * Return: void
 */


static void swap_with_prev(listint_t **list, listint_t *node)
{
	listint_t *prev = node->prev;

	/* Detach node from its place */
	prev->next = node->next;
	if (node->next)
		node->next->prev = prev;

	/*move node before prev*/
	node->prev = prev->prev;
	node->next = prev;

	if (prev->prev)
		prev->prev->next = node;
	else
		*list = node; /*node becomes new head*/
	prev->prev = node;
}
/**
 * insertion_sort_list - Sort a doubly linked list of ints in ascending order
 *                       using Insertion sort (by swapping nodes).
 * @list: Address of the head pointer
 *
 * Description: Prints the list after each swap using print_list.
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (node = (*list)->next; node; node = next)
	{
		/*save next before node possibly moves*/
		next = node->next;
		/*swap the current node backward to its correct position*/
		while (node->prev && node->n < node->prev->n)
		{
			swap_with_prev(list, node);
			print_list(*list);
		}
	}
}
