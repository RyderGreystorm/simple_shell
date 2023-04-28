#include "main.h"

/**
 * help_env - info on env
 */
void help_env(void)
{
	char *info = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, info, _strlen(info));
}

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
