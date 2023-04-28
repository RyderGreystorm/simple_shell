#include "main.h"

/**
 * error_1 - error handler
 * @args: buffer passed to the command
 * Return: error found
 */
char *error_1(char **args)
{
	char *error;
	int lenght;

	lenght = _strlen(err_name) + _strlen(args[0]) + 13;
	error = malloc(sizeof(char) * (lenght + 1));
	if (!error)
		return (NULL);

	_strcpy(error, "alias: ");
	_strcat(error, args[0]);
	_strcat(error, " not found\n");

	return (error);
}
