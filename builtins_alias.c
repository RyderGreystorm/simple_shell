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

/**
 * set_alias - set function
 * @var:  alias name
 * @value: alias value
 */
void set_alias(char *var, char *value)
{
	aliases_t *tmp = aliases;
	int len, j, l;
	char *new_value;

	*value = '\0';
	value++;
	len = _strlen(value) - _strspn(value, "'\"");
	new_value = malloc(sizeof(char) * (len + 1));
	if (!new_value)
		return;
	for (j = 0, l = 0; value[j]; j++)
	{
		if (value[j] != '\'' && value[j] != '"')
			new_value[l++] = value[j];
	}
	new_value[l] = '\0';
	while (tmp)
	{
		if (_strcmp(var, tmp->name) == 0)
		{
			free(tmp->value);
			tmp->value = new_value;
			break;
		}
		tmp = tmp->next;
	}
	if (!tmp)
		add_alias_end(&aliases, var, new_value);
}

/**
 * display_alias - print function
 * @alias: alias.
 */
void display_alias(aliases_t *alias)
{
	char *alias_string;
	int len = _strlen(alias->name) + _strlen(alias->value) + 4;

	alias_string = malloc(sizeof(char) * (len + 1));
	if (!alias_string)
		return;
	_strcpy(alias_string, alias->name);
	_strcat(alias_string, "='");
	_strcat(alias_string, alias->value);
	_strcat(alias_string, "'\n");

	write(STDOUT_FILENO, alias_string, len);
	free(alias_string);
}
/**
 * replace_aliases - function of the prototype
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
				new_value = malloc(sizeof(char) * (_strlen(tmp->value) + 1));
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