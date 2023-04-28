#include "main.h"

/**
 * add_alias_end - operate on prev node
 * @head: A pointer to the head of the list
 * @name: alians name
 * @value: alias value
 * Return: pointer to new node
 */
aliases_t *add_alias_end(aliases_t **head, char *name, char *value)
{
	aliases_t *new_node = malloc(sizeof(aliases_t));
	aliases_t *prev;

	if (!new_node)
		return (NULL);

	new_node->next = NULL;
	new_node->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if (!new_node->name)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = value;
	_strcpy(new_node->name, name);

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
