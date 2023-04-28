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
