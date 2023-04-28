#include "main.h"

/**
 * get_args - reads args
 * @buffer: buffer
 * @exe: points to str returned
 * Return: args readfrom cmd line
 */
char *get_args(char *buffer, int *exe)
{
	size_t size = 0;
	ssize_t fd;
	char *prompt = "FavShell$ ";

	if (buffer)
		free(buffer);

	fd = _getline(&buffer, &size, STDIN_FILENO);
	if (fd == -1)
		return (NULL);
	if (fd == 1)
	{
		hist++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, 6);
		return (get_args(buffer, exe));
	}

	buffer[fd - 1] = '\0';
	variable_replacement(&buffer, exe);
	handle_line(&buffer, fd);

	return (buffer);
}

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

/**
 * run_args - execute arguments
 * @args: args in array.
 * @buff: buffer.
 * @exe: last cmd return value.
 * Return: last executed command status value.
 */
int run_args(char **args, char **buff, int *exe)
{
	int ret1, l;
	int (*builtin)(char **args, char **buff);

	builtin = get_builtin(args[0]);

	if (builtin)
	{
		ret1 = builtin(args + 1, buff);
		if (ret1 != EXIT_VAR)
			*exe = ret1;
	}
	else
	{
		*exe = execute(args, buff);
		ret1 = *exe;
	}

	hist++;

	for (l = 0; args[l]; l++)
		free(args[l]);

	return (ret1);
}

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

/**
 * check_args - handles args read
 * @args: pointer to tokenize args.
 * Return: error for wrong delims
 */
int check_args(char **args)
{
	size_t pos;
	char *cur, *nex;

	for (pos = 0; args[pos]; pos++)
	{
		cur = args[pos];
		if (cur[0] == ';' || cur[0] == '&' || cur[0] == '|')
		{
			if (pos == 0 || cur[1] == ';')
				return (handle_error(&args[pos], 2));
			nex = args[pos + 1];
			if (nex && (nex[0] == ';' || nex[0] == '&' || nex[0] == '|'))
				return (handle_error(&args[pos + 1], 2));
		}
	}
	return (0);
}
