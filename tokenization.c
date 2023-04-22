#include "main.h"

/**
 * tokenization - it tokenize the input string into individual words
 * and store them in an array.
 * @buffer: a pointer to the input string that needs to be tokenized.
 * Return: a pointer to an array of strings.
 */

char **tokenization(char *buffer)
{
	int j = 0;
	char **argv;
	char *buffer_cpy = NULL;
	const char *delim = " \n";
	int tokenNum = 0; /**number of tokens from stdin*/
	char *token; /**Pointer to tokenized string*/
	ssize_t buffSize = sizeof(buffer) / sizeof(char *);

	/*TOKENIZATION*/
	buffer_cpy = malloc(sizeof(char) * buffSize);
	if (buffer_cpy == NULL)
	{
		perror("tsh: memory allocation failure");
		exit(EXIT_FAILURE);
	}

	_strcpy(buffer_cpy, buffer); /**Make a copy of buffer's string*/

	/**create space for the pointer to to the tokenized string*/
	token = strtok(buffer, delim);

	while (token != NULL)
	{
		tokenNum++;
		token = strtok(NULL, delim);
	}
	tokenNum++;

	/**allocate space for array that will hold tokens*/
	argv = malloc(sizeof(char *) * tokenNum);

	token = strtok(buffer_cpy, delim); /**Storing each token in the array*/

	for (j = 0; token != NULL; j++)
	{
		argv[j] = malloc(sizeof(char) * strlen(token));
		_strcpy(argv[j], token);
		token = strtok(NULL, delim);
	}
	argv[j] = NULL;
	return (argv);
}
