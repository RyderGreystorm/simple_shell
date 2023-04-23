#include "main.h"

/**
 * _strtok - it tokenize a string based on the specified delimiter character
 * and it prints each token to the standard output, one per line.
 * Return: 0 (success)
 */

int _strtok(void)
{
	char s[] = "Fafa and Favour";
	char delim = ' ';
	char *token;
	char *str;
	int length;

	str = s;
	while (*str != '\0')
	{
		/* find the next token */
		token = str;
		while (*str != delim && *str != '\0')
		{
			str++;
		}

		/* print the token */
		if (token != str)
		{
			length = str - token;
			write(STDOUT_FILENO, token, length);
			write(STDOUT_FILENO, "\n", 1);
		}

		/* move to the next string position */
		if (*str != '\0')
		{
			str++;
		}
	}

	return (0);
}
