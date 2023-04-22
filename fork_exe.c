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
	int status;

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
			waitpid(pid, &status, WUNTRACED);
		}
	while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
