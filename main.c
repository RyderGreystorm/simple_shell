#include "main.h"

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
