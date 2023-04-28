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
