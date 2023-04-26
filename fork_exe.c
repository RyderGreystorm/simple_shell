#include "main.h"

/**
 * fork_exe - creates a new process.
 * @argv: a pointer to an array of strings
 * that represent the command and its arguments.
 * Return: 1 (success)
 */

int fork_exe(char **argv)
{
	pid_t pid;
	int status = 0;

	pid = fork();
	if (pid == 0)
	{
		/*child process*/
		exec(argv);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0) /**Error forking*/
	{
		perror("lsh");
	}

	else
	{
		do {
			if (waitpid(pid, &status, WUNTRACED) == -1)
			{
				perror("lsh");
				status = -1;
				break;
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
