#include "main.h"

/**
 * forkStatus - it creates a fork process.
 * Return: 0 (Success)
 */

void forkStatus(void)
{
	pid_t pid = fork();
	int status;
	int  exit_status;

	pid = fork();

	exit_status = waitpid(pid, &status, WUNTRACED);
	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
	}
	else
	{
		exit_status = -1;
	}
	printf("%d", exit_status);

}
