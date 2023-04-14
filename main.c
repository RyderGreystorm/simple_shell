#include "main.h"

/**
 * main - entry level of our application
 * @argc: params for number of arguments
 * @argv: params as arary of chars
 * Return: 0 on success and 1 on fialure
 */


int main(void)
{
	char *prompt = "userhell$ ";
	char *buffer = NULL;
	size_t n = 0;
	ssize_t readNum;
	int i = 1;
	int j = 0;
	char **argv;
	char * buffer_cpy = NULL;
	const char *delim = " \n";
	int tokenNum = 0; /**number of tokens from stdin*/
	char *token; /**Pointer to tokenized string*/

	while (i)
	{
		printf("%s", prompt);

		readNum = getline(&buffer, &n, stdin);
	/*Checking if the getline function failed or user pressed CTRL + D*/
		if (readNum == -1)
		{
			perror("Error");
			return (-1);
		}

	
	/*TOKENIZATION*/
		buffer_cpy = malloc(sizeof(char) * readNum);
		if (buffer_cpy == NULL)
		{
			perror("tsh: memory allocation failure");
			return (-1);
		}

	/**Make a copy of buffer's string*/
		_strcpy(buffer_cpy, buffer);

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

	/**Storing each token in the array*/

		token = strtok(buffer_cpy, delim);

		for (j = 0; token != NULL; j++)
		{
			argv[j] = malloc(sizeof(char) * _strlen(token));
			_strcpy(argv[j], token);
			token = strtok(NULL, delim);
		}
		argv[j] = NULL;

		for (j = 0; j < tokenNum; j++)
			printf("%s\n", argv[j]);

		free(argv);
		free(buffer);
		free(buffer_cpy);

	}
	return (0);
}
