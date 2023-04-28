#include "main.h"


/**
 * sh_env - shell environment
 * @args: args params.
 * @ptr: pointer to argument.
 * Return: -1 on error, 0 on success
 */
int sh_env(char **args, char __attribute__((__unused__)) **ptr)
{
	int i;
	char nc = '\n';

	if (!environ)
		return (-1);

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, &nc, 1);
	}

	(void)args;
	return (0);
}
