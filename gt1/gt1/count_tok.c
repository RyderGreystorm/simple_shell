#include "main.h"

/**
 * count_tokens - count token
 * @token: token
 * @delim: delimiter
 * Return: strlen of token.
 */
int count_tokens(char *token, char *delim)
{
	int index, tokens = 0, len = 0;

	for (index = 0; *(token + index); index++)
		len++;

	for (index = 0; index < len; index++)
	{
		if (*(token + index) != *delim)
		{
			tokens++;
			index += token_length(token + index, delim);
		}
	}

	return (tokens);
}
