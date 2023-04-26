#include "main.h"

/**
 * main - entry level of our application
 * Return: 0 on success and 1 on fialure
 */


int main(void)
{
	char *prompt = "userhell$ ";
	int retStatus;
	char *buffer = NULL;
	char **args = NULL;

		do {
			_printf(prompt);
			buffer = readLine();
			args = tokenization(buffer);
			retStatus = executeBuiltIn(args);


		} while (retStatus);

	return (EXIT_SUCCESS);
}
