#include "main.h"

/**
 * change_aliases - function of the prototype
 * @args: 2D pointer to the arguments.
 *
 * Return: 2D pointer to the arguments.
 */
char **change_aliases(char **args)
{
	aliases_t *tmp;
	int x;
	char *new_value;

	if (_strcmp(args[0], "alias") == 0)
		return (args);
	for (x = 0; args[x]; x++)
	{
		tmp = aliases;
		while (tmp)
		{
			if (_strcmp(args[x], tmp->name) == 0)
			{
				new_value = malloc(sizeof(char) *
						(_strlen(tmp->value) + 1));
				if (!new_value)
				{
					free_args(args, args);
					return (NULL);
				}
				_strcpy(new_value, tmp->value);
				free(args[x]);
				args[x] = new_value;
				x--;
				break;
			}
			tmp = tmp->next;
		}
	}

	return (args);
}
