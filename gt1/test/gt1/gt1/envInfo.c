#include "main.h"

/**
 * help_env - info on env
 */
void help_env(void)
{
	char *info = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, info, _strlen(info));
}

