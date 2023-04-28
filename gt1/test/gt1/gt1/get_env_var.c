#include "main.h"
/**
 * get_env_value - env value
 * @needle: var in search for
 * @haystack: var length
 *
 * Return: value fo the replace vairable or empty string
 */
char *get_env_value(char *needle, int haystack)
{
	char **var_ptr;
	char *replace = NULL, *tmp, *var;

	var = malloc(haystack + 1);
	if (!var)
		return (NULL);
	var[0] = '\0';
	_strncat(var, needle, haystack);

	var_ptr = _getenv(var);
	free(var_ptr);
	if (var)
	{
		tmp = *var_ptr;
		while (*tmp != '=')
			tmp++;
		tmp++;
		replace = malloc(_strlen(tmp) + 1);
		if (replace)
			_strcpy(replace, tmp);
	}
	return (replace);
}
