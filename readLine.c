#include "main.h"

/**
 * readLine: takes from the standard input
 * Return: buffer with line read
 */
char *readLine(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;

	if (getline(&buffer, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			_printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("error");
			exit(EXIT_FAILURE);
		}
	}

return (buffer);
}
