#include "main.h"

/**
 * env_builtin - prints out the current environment variables
 * that are set in the operating system's environment.
 * @args: argument vector 0
 */

void env_builtin(char **args)
{

	char **unix_env = environ;

	(void) (args);
	while (*unix_env != NULL)
	{
		_printf(*unix_env);
		_putchar('\n');
		unix_env++;
	}
}
