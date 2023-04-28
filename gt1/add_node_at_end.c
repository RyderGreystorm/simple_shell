#include "main.h"

/**
 * add_node_end - add node to the end of list
 * @head: pointer to the first node
 * @dir: new path
 * Return: pointer to new node
 */
lists_t *add_node_end(lists_t **head, char *dir)
{
	lists_t *new_node = malloc(sizeof(lists_t));
	lists_t *prev;

	if (!new_node)
		return (NULL);

	new_node->dir = dir;
	new_node->next = NULL;

	if (*head)
	{
		prev = *head;
		while (prev->next != NULL)
			prev = prev->next;
		prev->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}
