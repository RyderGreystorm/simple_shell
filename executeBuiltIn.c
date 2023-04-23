#include "main.h"

/**
 * executeBuiltIn - it executes built-in commands within a shell.
 * @argv: a pointer to an array of strings,
 * which holds the command and its arguments to be executed.
 * Return: the file being called in the terminal.
 */
int executeBuiltIn(char **argv)
{
	char *parsedStr[] = { "exit", "cd", "env", "setenv", "unsetenv"};

	void (*parsedFunc[]) (char **) = { &exit_func, &chdirectory, &env_builtin, &setEnv, &unsetEnv};

	int parsedSize = sizeof(parsedStr) / sizeof(char *);
	int i;

	if (argv[0] == NULL)
		return (1);

	for (i = 0; i < parsedSize; i++)
	{
		if (strcmp(argv[0], parsedStr[i]) == 0)
		{
			(*parsedFunc[i]) (argv);
			break;
		}
	}
	return (fork_exe(argv));
}
