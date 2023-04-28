#include "main.h"

/**
 * help_setenv - inf on setenv.
 */
void help_setenv(void)
{
	char *info = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, info, _strlen(info));
	info = "environment variable, or modifies an existing one.\n\n";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "\tUpon failure, prints a message to stderr.\n";
	write(STDOUT_FILENO, info, _strlen(info));
}
