#include "main.h"

/**
 * token_length - finds size of token
 * @token: token.
 * @delim: The delim.
 * Return: index of delmin
 */
int token_length(char *token, char *delim)
{
	int index = 0, len = 0;

	while (*(token + index) && *(token + index) != *delim)
	{
		len++;
		index++;
	}

	return (len);
}
