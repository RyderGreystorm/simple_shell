#include "main.h"

/**
 * error_env - error in the environment variable
 * @args: buffer passed to the command
 * Return: error found
 */
char *error_env(char **args)
{
	char *error, *_histStr;
	int lenght;

	_histStr = _itoa(hist);
	if (!_histStr)
		return (NULL);

	args--;
	lenght = _strlen(err_name) + _strlen(_histStr) + _strlen(args[0]) + 45;
	error = malloc(sizeof(char) * (lenght + 1));
	if (!error)
	{
		free(_histStr);
		return (NULL);
	}

	_strcpy(error, err_name);
	_strcat(error, ": ");
	_strcat(error, _histStr);
	_strcat(error, ": ");
	_strcat(error, args[0]);
	_strcat(error, ": Unable to add/remove from environment\n");

	free(_histStr);
	return (error);
}
