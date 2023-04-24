#include "main.h"

/**
 * exit_func - it causes normal process termination.
 * @args: a parameter that is passed to the function,
 * the function expects to receive a pointer to a pointer to a character.
 */

void exit_func(char **args)
{
	char *ptr;
	int status;

	if (args[0] == NULL)
		exit(EXIT_SUCCESS);
	status = strtol(args[0], &ptr, 10);
	if (*ptr != '\0' || errno == ERANGE)
	{
		fprintf(stderr, "Invalid exit status: %s\n", args[0]);
		exit(EXIT_FAILURE);
	}
	exit(status);
}
