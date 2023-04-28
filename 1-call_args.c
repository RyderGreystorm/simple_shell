#include "main.h"

/**
 * call_args - find args to be parsed
 * @args: buffer.
 * @buf: A double pointer to the beginning of argument.
 * @exe: The return value of the parent process' last executed command.
 * Return: The return value of the last executed command.
 */
int call_args(char **args, char **buf, int *exe)
{
	int token, i;

	if (!args[0])
		return (*exe);
	for (i = 0; args[i]; i++)
	{
		if (_strncmp(args[i], "||", 2) == 0)
		{
			free(args[i]);
			args[i] = NULL;
			args = change_aliases(args);
			token = run_args(args, buf, exe);
			if (*exe != 0)
			{
				args = &args[++i];
				i = 0;
			}
			else
			{
				for (i++; args[i]; i++)
					free(args[i]);
				return (token);
			}
		}
		else if (_strncmp(args[i], "&&", 2) == 0)
		{
			free(args[i]);
			args[i] = NULL;
			args = change_aliases(args);
			token = run_args(args, buf, exe);
			if (*exe == 0)
			{
				args = &args[++i];
				i = 0;
			}
			else
			{
				for (i++; args[i]; i++)
					free(args[i]);
				return (token);
			}
		}
	}
	args = change_aliases(args);
	token = run_args(args, buf, exe);
	return (token);
}
