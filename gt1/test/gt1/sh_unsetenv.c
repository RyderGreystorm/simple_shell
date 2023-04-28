#include "main.h"

/**
 * shell_unsetenv - unset env
 * @args: args params
 * @ptr: args params
 * Return: -1 on error, 0 on success
 */
int sh_unsetenv(char **args, char __attribute__((__unused__)) **ptr)
{
	char **var_env, **new_environ;
	size_t size;
	int index, index2;

	if (!args[0])
		return (handle_error(args, -1));
	var_env = _getenv(args[0]);
	if (!var_env)
		return (0);

	for (size = 0; environ[size]; size++)
		;

	new_environ = malloc(sizeof(char *) * size);
	if (!new_environ)
		return (handle_error(args, -1));

	for (index = 0, index2 = 0; environ[index]; index++)
	{
		if (*var_env == environ[index])
		{
			free(*var_env);
			continue;
		}
		new_environ[index2] = environ[index];
		index2++;
	}
	free(environ);
	environ = new_environ;
	environ[size - 1] = NULL;

return (0);
}


