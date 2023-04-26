#include "main.h"
/**
 * tokenization - tokenize the string into single arguments
 * @buffer: buffer from getline function
 * Return: tokenized string as pointer to pointer
 */
char **tokenization(char *buffer)
{
	int j = 0, tokenNum = 0, k;
	char **argv = NULL;
	char *buffer_cpy = NULL, *token = NULL;
	const char *delim = " \n";
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
	token = strtok(buffer_cpy, delim); /**Storing each token in the array*/

	for (j = 0; token != NULL; j++)
	{
		argv[j] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (argv[j] == NULL)
		{
			perror("tsh: memory allocation failure");
			for (k = j - 1; k >= 0; k--)
			{
				free(argv[k]);
			}
		}
		_strcpy(argv[j], token);
		token = strtok(NULL, delim);
	}
	argv[j] = NULL;
	free(buffer_cpy);
	return (argv);
}
