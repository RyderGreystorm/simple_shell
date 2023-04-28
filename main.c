#include "main.h"

	char *err_name ;
	int hist;
	aliases_t *aliases;

/**
 * sig_handler - waits for signal
 * @sign: signal.
 */
void sig_handler(int sign)
{
	char *err_name __attribute__((unused));
	int hist __attribute__((unused));
	aliases_t *aliases __attribute__((unused));
	char *new_prompt = "\nFavShell$ ";

	(void)sign;
	signal(SIGINT, sig_handler);
	write(STDIN_FILENO, new_prompt, 6);
}

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

/**
 * main - funtion to ru the shell
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: The return value of the last executed command.
 */
int main(int argc, char *argv[])
{
	int rtn = 0, retn;
	int *exe_ret = &retn;
	char *prompt = "FavShell$ ", *new_line = "\n";

	err_name = argv[0];
	hist = 1;
	aliases = NULL;
	signal(SIGINT, sig_handler);

	*exe_ret = 0;
	environ = _cpyenv();
	if (!environ)
		exit(-100);

	if (argc != 1)
	{
		rtn = _file_commands(argv[1], exe_ret);
		free_env();
		free_alias_list(aliases);
		return (*exe_ret);
	}

	if (!isatty(STDIN_FILENO))
	{
		while (rtn != E_O_F && rtn != EXIT_VAR)
			rtn = handle_args(exe_ret);
		free_env();
		free_alias_list(aliases);
		return (*exe_ret);
	}

	while (1)
	{
		write(STDOUT_FILENO, prompt, 10);
		rtn = handle_args(exe_ret);
		if (rtn == E_O_F || rtn == EXIT_VAR)
		{
			if (rtn == E_O_F)
				write(STDOUT_FILENO, new_line, 1);
			free_env();
			free_alias_list(aliases);
			exit(*exe_ret);
		}
	}

	free_env();
	free_alias_list(aliases);
	return (*exe_ret);
}
