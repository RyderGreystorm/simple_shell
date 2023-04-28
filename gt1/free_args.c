#include "main.h"

/**
 * free_args - free arguments read
 * @args: cmd buffer with null terminator
 * @ptr: buffer pointer.
 */
void free_args(char **args, char **ptr)
{
	size_t len1;

	for (len1 = 0; args[len1] || args[len1 + 1]; len1++)
		free(args[len1]);

	free(ptr);
}

