#include "main.h"

/**
 * main - entry level of our application
 * Return: 0 on success and 1 on fialure
 */


int main(int argc, char **argv)
{
	char *buffer = NULL;
	size_t buffsize = 0;
	pid_t pid = 0;
	int status = 0;

	(void)(argc);
	buffer = malloc(sizeof(char) * CMD_LEN);
	if (!buffer)
	{
		perror("Memory");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		_printf(SHELL);
		if (getline(&buffer, &buffsize, stdin) == -1)
		{
			if (feof(stdin))
			{
				perror("eof");
				break;
			}
			perror("eof");
			exit(EXIT_FAILURE);
		}
		buffer[my_strcspn(buffer, "\n")] = 0;
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(buffer, argv, NULL) == -1)
			{
				perror("");
				exit(EXIT_FAILURE);
			}
			else
			{
				if (wait(&status) == -1)
				{
					perror("wait");
					exit(EXIT_FAILURE);
				}
				if (WIFEXITED(status))
				{
					_printf("Exited with status ");
					_putchar(status);
					_putchar('\n');
				}
				else if (WIFSIGNALED(status))
				{_printf("Terminated by signal");
					_putchar(status);
					_putchar('\n');
				}
			}
		}
	}
	free(buffer);
	return (EXIT_SUCCESS);
}
