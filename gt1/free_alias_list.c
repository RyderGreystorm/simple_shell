#include "main.h"

/**
 * free_alias_list - free node
 * @head: THe head pointer
 */
void free_alias_list(aliases_t *head)
{
	aliases_t *next;

	while (head)
	{
		next = head->next;
		free(head->name);
		free(head->value);
		free(head);
		head = next;
	}
}
