#include "main.h"

/**
 * help_unsetenv - info on unsetenv
 */
void help_unsetenv(void)
{
	char *info = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, info, _strlen(info));
	info = "environmental variable.\n\n\tUpon failure, prints a ";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "message to stderr.\n";
	write(STDOUT_FILENO, info, _strlen(info));
}
