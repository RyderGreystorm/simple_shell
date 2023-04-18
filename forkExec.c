#include "main.h"

/**
 * fork_exe - forks a process and calls the exec
 * function on it to run another program
 * @argv: filename
 * Return: 1 on sucess
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
	else if (pid < 0)
	/**Error forking*/
		perror("lsh");
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);

		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
