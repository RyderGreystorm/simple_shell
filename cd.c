#include "main.h"

/**
 * _cd - it changes the current working directory of the shell.
 * @args: parameter used to pass the command-line arguments to the function.
 */

void _cd(char **args)
{
	if (args[1] == NULL)
	{
		perror("cd: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
		}
	}
}
