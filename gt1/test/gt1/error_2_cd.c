#include "main.h"

/**
 * error_2_cd - cd error handler
 * @args: buffer passed to the command
 * Return: The error.
 */
char *error_2_cd(char **args)
{
	char *error, *_histStr;
	int lenght;

	_histStr = _itoa(hist);
	if (!_histStr)
		return (NULL);

	if (args[0][0] == '-')
		args[0][2] = '\0';
	lenght = _strlen(err_name) + _strlen(_histStr) + _strlen(args[0]) + 24;
	error = malloc(sizeof(char) * (lenght + 1));
	if (!error)
	{
		free(_histStr);
		return (NULL);
	}

	_strcpy(error, err_name);
	_strcat(error, ": ");
	_strcat(error, _histStr);
	if (args[0][0] == '-')
		_strcat(error, ": cd: Illegal option ");
	else
		_strcat(error, ": cd: can't cd to ");
	_strcat(error, args[0]);
	_strcat(error, "\n");

	free(_histStr);
	return (error);
}
