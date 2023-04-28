#include "main.h"

/**
 * error_2_exit - exit error
 * @args: buffer passed to the command
 * Return: The error
 */
char *error_2_exit(char **args)
{
	char *error, *_histStr;
	int lenght;

	_histStr = _itoa(hist);
	if (!_histStr)
		return (NULL);

	lenght = _strlen(err_name) + _strlen(_histStr) + _strlen(args[0]) + 27;
	error = malloc(sizeof(char) * (lenght + 1));
	if (!error)
	{
		free(_histStr);
		return (NULL);
	}

	_strcpy(error, err_name);
	_strcat(error, ": ");
	_strcat(error, _histStr);
	_strcat(error, ": exit: Illegal number: ");
	_strcat(error, args[0]);
	_strcat(error, "\n");

	free(_histStr);
	return (error);
}
