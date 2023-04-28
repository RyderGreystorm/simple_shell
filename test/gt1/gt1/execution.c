#include "main.h"
/**
 * execute - executes a command
 * @args: args array
 * @bufptr: pointer to buffer
 * Return: status of query
 */
int execute(char **args, char **bufptr)
{
	pid_t pid;
	int status, flag = 0, rtn = 0;
	char *cmd = args[0];

	if (cmd[0] != '/' && cmd[0] != '.')
	{
		flag = 1;
		cmd = get_location(cmd);
	}

	if (!cmd || (access(cmd, F_OK) == -1))
	{
		if (errno == EACCES)
			rtn = (handle_error(args, 126));
		else
			rtn = (handle_error(args, 127));
	}
	else
	{
		pid = fork();
		if (pid == -1)
		{
			if (flag)
				free(cmd);
			perror("Error child:");
			return (1);
		}
		if (pid == 0)
		{
			execve(cmd, args, environ);
			if (errno == EACCES)
				rtn = (handle_error(args, 126));
			free_env();
			free_args(args, bufptr);
			free_alias_list(aliases);
			_exit(rtn);
		}
		else
		{
			wait(&status);
			rtn = WEXITSTATUS(status);
		}
	}
	if (flag)
		free(cmd);
	return (rtn);
}
