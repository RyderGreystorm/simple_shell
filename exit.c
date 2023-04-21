#include "main.h"

/**
 * exit_func - it causes normal process termination.
 * @args: a parameter that is passed to the function,
 * the function expects to receive a pointer to a pointer to a character.
 */

void exit_func(char **args)
{
	(void) (args);
	exit(0);
}
