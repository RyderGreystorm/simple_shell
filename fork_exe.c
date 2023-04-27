#include "main.h"

/**
 * fork_exe - creates a new process.
 * @argv: a pointer to an array of strings
 * that represent the command and its arguments.
 * Return: 1 (success)
 */

void fork_exe(char **argv)
{
	pid_t pid;
	int status = 0;
	char *cmd = NULL, *newPath = NULL;

	if (argv)
	{
		cmd = argv[0];
		newPath = get_path(cmd);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(newPath, argv, NULL) == -1)
		{
			perror("error");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0) /**Error forking*/
	{
		perror("lsh");
	}

	else
	{
		if (waitpid(pid, &status, WUNTRACED) == -1)
		{
			perror("lsh");
		}
		if (!WIFEXITED(status) && !WIFSIGNALED(status) == 0)
			return;

	}
}
