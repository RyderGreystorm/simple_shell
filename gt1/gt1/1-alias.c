#include "main.h"

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
