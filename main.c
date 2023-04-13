#include "main.h"

/**
 * main - entry level of our application
 * @argc: params for number of arguments
 * @argv: params as arary of chars
 * Return: 0 on success and 1 on fialure
 */


int main(int argc, char **argv)
{
	char *prompt = "favourShell$ ";
	char *buffer = NULL;
	size_t n;
	ssize_t readNum;
	int i = 1;

	(void)argc;
	(void)argv;

	while (i)
	{
		printf("%s", prompt);

		readNum = getline(&buffer, &n, stdin);
		if (readNum == -1)
		{
			printf("Error\n");
			return (-1);
		}
		printf("\n%s\n", buffer);
		printf("%ld\n", readNum);
		free(buffer);
	}

	return (0);
}
