#include "main.h"

/**
 * _strtok - tokenization function.
 * @buffer: buffer.
 * @delim: The delimiter
 *
 * Return: A pointer to an array .
 */
char **_strtok(char *buffer, char *delim)
{
	char **ptr;
	int index = 0, tokens, pos, strlen, k;

	tokens = count_tokens(buffer, delim);
	if (tokens == 0)
		return (NULL);

	ptr = malloc(sizeof(char *) * (tokens + 2));
	if (!ptr)
		return (NULL);

	for (pos = 0; pos < tokens; pos++)
	{
		while (buffer[index] == *delim)
			index++;

		strlen = token_length(buffer + index, delim);

		ptr[pos] = malloc(sizeof(char) * (strlen + 1));
		if (!ptr[pos])
		{
			for (index -= 1; index >= 0; index--)
				free(ptr[index]);
			free(ptr);
			return (NULL);
		}

		for (k = 0; k < strlen; k++)
		{
			ptr[pos][k] = buffer[index];
			index++;
		}

		ptr[pos][k] = '\0';
	}
	ptr[pos] = NULL;
	ptr[pos + 1] = NULL;

	return (ptr);
}
