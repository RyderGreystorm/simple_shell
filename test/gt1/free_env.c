#include "main.h"

/**
 * free_env - free env.
 * Return: void
 */
void free_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		free(environ[i]);
	free(environ);
}
