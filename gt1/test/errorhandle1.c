#include "main.h"

char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);
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
