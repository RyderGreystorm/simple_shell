#include "main.h"

/**
 * tkenization - it tokenize the input string into individual words
 * and store them in an array.
 * @buffer: a pointer to the input string that needs to be tokenized.
 * Return: a pointer to an array of strings.
 */

char **tkenization(char *buffer)
{
	int j = 0, tokenNum = 0;
	char **argv = NULL;
	char *buffer_cpy = NULL;
	char *token = NULL;
	const char *delim = " \n";

	if (buffer == NULL)
		return (NULL);
	size_t buffSize = _strlen(buffer);

	buffer_cpy = malloc(sizeof(char) * (buffSize + 1));
	if (buffer_cpy == NULL)
	{
		perror("tsh: memory allocation failure");
		exit(EXIT_FAILURE);
	}
	_strcpy(buffer_cpy, buffer); /**Make a copy of buffer's string*/
	token = strtok(buffer, delim);
	while (token != NULL)
	{
		tokenNum++;
		token = strtok(NULL, delim);
	}
	tokenNum++;
	argv = malloc(sizeof(char *) * tokenNum);
	if (argv == NULL)
		exit(EXIT_FAILURE);
	token = strtok(buffer_cpy, delim); /**Storing each token in the array*/
	for (j = 0; token != NULL; j++)
	{
		argv[j] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (argv[j] == NULL)
		{
			perror("tsh: memmory allocation failure");
		}
		_strcpy(argv[j], token);
		token = strtok(NULL, delim);
	}
	argv[j] = NULL;
	free(buffer_cpy);
	return (argv);
}
