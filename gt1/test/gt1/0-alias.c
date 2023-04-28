#include "main.h"

/**
 * my_alias - set alias
 * @args: aargs params.
 * @node: ptr to argument.
 *
 * Return:  -1 for failure, 0 for success
 */
int my_alias(char **args, char __attribute__((__unused__)) **node)
{
	aliases_t *tmp = aliases;
	int x, ret = 0;
	char *value;

	if (!args[0])
	{
		while (tmp)
		{
			display_alias(tmp);
			tmp = tmp->next;
		}
		return (ret);
	}
	for (x = 0; args[x]; x++)
	{
		tmp = aliases;
		value = _strchr(args[x], '=');
		if (!value)
		{
			while (tmp)
			{
				if (_strcmp(args[x], tmp->name) == 0)
				{
					display_alias(tmp);
					break;
				}
				tmp = tmp->next;
			}
			if (!tmp)
				ret = handle_error(args + x, 1);
		}
		else
			set_alias(args[x], value);
	}
	return (ret);
}
