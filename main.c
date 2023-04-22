#include "main.h"

/**
 * main - entry level of our application
 * Return: 0 on success and 1 on fialure
 */


int main(void)
{
	char *prompt = "userhell$ ";
	int retStatus;
	char *buffer;
	char **args;

		do {
			_printf(prompt);
			buffer = get_input();
			args = tokenization(buffer);
			retStatus = executeBuiltIn(args);

			free(buffer);
			free(args);

		} while (retStatus);
		free(buffer);
		free(args);

	return (EXIT_SUCCESS);
}
