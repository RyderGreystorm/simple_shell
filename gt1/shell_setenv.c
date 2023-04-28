#include "main.h"

/**
 * sh_setenv - enset env
 * @args: params
 * @ptr: args params
 * Return: on error, -1
 */
int sh_setenv(char **args, char __attribute__((__unused__)) **ptr)
{
	char **var_env = NULL, **new_environ, *new_value;
	size_t size;
	int i;

	if (!args[0] || !args[1])
		return (handle_error(args, -1));

	new_value = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
	if (!new_value)
		return (handle_error(args, -1));
	_strcpy(new_value, args[0]);
	_strcat(new_value, "=");
	_strcat(new_value, args[1]);

	var_env = _getenv(args[0]);
	if (var_env)
	{
		free(*var_env);
		*var_env = new_value;
		return (0);
	}
	for (size = 0; environ[size]; size++)


		new_environ = malloc(sizeof(char *) * (size + 2));
	if (!new_environ)
	{
		free(new_value);
		return (handle_error(args, -1));
	}

	for (i = 0; environ[i]; i++)
		new_environ[i] = environ[i];

	free(environ);
	environ = new_environ;
	environ[i] = new_value;
	environ[i + 1] = NULL;

	return (0);
}
