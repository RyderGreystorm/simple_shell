#include "main.h"


/**
 * get_builtin - finds builtin in array
 * @cmd: The command in search
 * Return: function pointer
 */
int (*get_builtin(char *cmd))(char **args, char **adv)
{
	builtins_t funcs[] = {
		{ "exit", sh_exit },
		{ "env", sh_env },
		{ "setenv", sh_setenv },
		{ "unsetenv", sh_unsetenv },
		{ "cd", sh_cd },
		{ "alias", my_alias },
		{ "help", sh_help },
		{ NULL, NULL }
	};
	int l;

	for (l = 0; funcs[l].name; l++)
	{
		if (_strcmp(funcs[l].name, cmd) == 0)
			break;
	}
	return (funcs[l].f);
}

/**
 * sh_exit - exit function
 * @args: aargs params
 * @adv: pointer to buffer.
 * Return: status of query
 */
int sh_exit(char **args, char **adv)
{
	int l = 0, len_of_int = 10;
	unsigned int num = 0, max = 1 << (sizeof(int) * 8 - 1);

	if (args[0])
	{
		if (args[0][0] == '+')
		{
			l = 1;
			len_of_int++;
		}
		for (; args[0][l]; l++)
		{
			if (l <= len_of_int && args[0][l] >= '0' && args[0][l] <= '9')
				num = (num * 10) + (args[0][l] - '0');
			else
				return (handle_error(--args, 2));
		}
	}
	else
	{
		return (-3);
	}
	if (num > max - 1)
		return (handle_error(--args, 2));
	args -= 1;
	free_args(args, adv);
	free_env();
	free_alias_list(aliases);
	exit(num);
}

/**
 * sh_cd - fchange dir
 * @args: args params
 * @adv: pointer to buff
 * Return: status of query
 */
int sh_cd(char **args, char __attribute__((__unused__)) **adv)
{
	char **dir_info, *buff = "\n";
	char *oldpwd = NULL, *pwd = NULL;
	struct stat dir;

	oldpwd = getcwd(oldpwd, 0);
	if (!oldpwd)
		return (-1);

	if (args[0])
	{
		if (*(args[0]) == '-' || _strcmp(args[0], "--") == 0)
		{
			if ((args[0][1] == '-' && args[0][2] == '\0') ||
					args[0][1] == '\0')
			{
				if (_getenv("OLDPWD") != NULL)
					(chdir(*_getenv("OLDPWD") + 7));
			}
			else
			{
				free(oldpwd);
				return (handle_error(args, 2));
			}
		}
		else
		{
			if (stat(args[0], &dir) == 0 && S_ISDIR(dir.st_mode)
					&& ((dir.st_mode & S_IXUSR) != 0))
				chdir(args[0]);
			else
			{
				free(oldpwd);
				return (handle_error(args, 2));
			}
		}
	}
	else
	{
		if (_getenv("HOME") != NULL)
			chdir(*(_getenv("HOME")) + 5);
	}

	pwd = getcwd(pwd, 0);
	if (!pwd)
		return (-1);

	dir_info = malloc(sizeof(char *) * 2);
	if (!dir_info)
		return (-1);

	dir_info[0] = "OLDPWD";
	dir_info[1] = oldpwd;
	if (sh_setenv(dir_info, dir_info) == -1)
		return (-1);

	dir_info[0] = "PWD";
	dir_info[1] = pwd;
	if (sh_setenv(dir_info, dir_info) == -1)
		return (-1);
	if (args[0] && args[0][0] == '-' && args[0][1] != '-')
	{
		write(STDOUT_FILENO, pwd, _strlen(pwd));
		write(STDOUT_FILENO, buff, 1);
	}
	free(oldpwd);
	free(pwd);
	free(dir_info);
	return (0);
}

/**
 * sh_help - information
 * @args: args array
 * @adv: pointer to buff
 * Return: status of query
 */
int sh_help(char **args, char __attribute__((__unused__)) **adv)
{
	if (!args[0])
		help_all();
	else if (_strcmp(args[0], "alias") == 0)
		help_alias();
	else if (_strcmp(args[0], "cd") == 0)
		help_cd();
	else if (_strcmp(args[0], "exit") == 0)
		help_exit();
	else if (_strcmp(args[0], "env") == 0)
		help_env();
	else if (_strcmp(args[0], "setenv") == 0)
		help_setenv();
	else if (_strcmp(args[0], "unsetenv") == 0)
		help_unsetenv();
	else if (_strcmp(args[0], "help") == 0)
		help_help();
	else
		write(STDERR_FILENO, err_name, _strlen(err_name));

	return (0);
}
