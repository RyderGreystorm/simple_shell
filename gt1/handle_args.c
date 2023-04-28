#include "main.h"

/**
 * handle_args - args handler
 * @exe: vale of ppid
 * Return: eof -2; invalid token -1
 */
int handle_args(int *exe)
{
	int ret2 = 0, i;
	char **args, *buffer = NULL, **next;

	buffer = get_args(buffer, exe);
	if (!buffer)
		return (E_O_F);

	args = _strtok(buffer, " ");
	free(buffer);
	if (!args)
		return (ret2);
	if (check_args(args) != 0)
	{
		*exe = 2;
		free_args(args, args);
		return (*exe);
	}
	next = args;

	for (i = 0; args[i]; i++)
	{
		if (_strncmp(args[i], ";", 1) == 0)
		{
			free(args[i]);
			args[i] = NULL;
			ret2 = call_args(args, next, exe);
			args = &args[++i];
			i = 0;
		}
	}
	if (args)
		ret2 = call_args(args, next, exe);

	free(next);
	return (ret2);
}
