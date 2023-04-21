#include "main.h"

/**
 * env_builtin - prints out the current environment variables
 * that are set in the operating system's environment.
 */

void env_builtin(void)
{

	char **unix_env = environ;

	while (*unix_env != NULL)
	{
		_printf("%s\n", *unix_env);
		unix_env++;
	}
}
