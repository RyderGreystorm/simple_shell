#include "main.h"

/**
 * main - entry level of our application
 * Return: 0 on success and 1 on fialure
 */


int main(void)
{
	char *buffer = NULL;
	char **args = NULL;

		while (1)
		{
			buffer = readLine();
			args = tokenization(buffer);
			fork_exe(args);
		}


	return (EXIT_SUCCESS);
}
