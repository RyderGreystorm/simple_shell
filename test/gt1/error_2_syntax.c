#include "main.h"

/**
 * error_2_syntax - syntax error handler
 * @args: buffer of arguments
 * Return: The error
 */
char *error_2_syntax(char **args)
{
	char *error, *_histStr;
	int lenght;

	_histStr = _itoa(hist);
	if (!_histStr)
		return (NULL);

	lenght = _strlen(err_name) + _strlen(_histStr) + _strlen(args[0]) + 33;
	error = malloc(sizeof(char) * (lenght + 1));
	if (!error)
	{
		free(_histStr);
		return (NULL);
	}

	_strcpy(error, err_name);
	_strcat(error, ": ");
	_strcat(error, _histStr);
	_strcat(error, ": Syntax error: \"");
	_strcat(error, args[0]);
	_strcat(error, "\" unexpected\n");

	free(_histStr);
	return (error);
}
