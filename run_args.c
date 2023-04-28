#include "main.h"

/**
 * run_args - execute arguments
 * @args: args in array.
 * @buff: buffer.
 * @exe: last cmd return value.
 * Return: last executed command status value.
 */
int run_args(char **args, char **buff, int *exe)
{
	int ret1, l;
	int (*builtin)(char **args, char **buff);

	builtin = get_builtin(args[0]);

	if (builtin)
	{
		ret1 = builtin(args + 1, buff);
		if (ret1 != EXIT_VAR)
			*exe = ret1;
	}
	else
	{
		*exe = execute(args, buff);
		ret1 = *exe;
	}

	hist++;

	for (l = 0; args[l]; l++)
		free(args[l]);

	return (ret1);
}
