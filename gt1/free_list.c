#include "main.h"

/**
 * free_list - free the pointers
 * @head: head pointer
 */
void free_list(lists_t *head)
{
	lists_t *next;

	while (head)
	{
		next = head->next;
		free(head->dir);
		free(head);
		head = next;
	}
}
