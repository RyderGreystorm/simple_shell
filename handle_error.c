#include "main.h"

/**
 * handle_error - error handling
 * @str_arg: arg params.
 * @err: error.
 * Return: value of error.
 */
int handle_error(char **str_arg, int err)
{
	char *error;

	switch (err)
	{
		case -1:
			error = error_env(str_arg);
			break;
		case 1:
			error = error_1(str_arg);
			break;
		case 2:
			if (*(str_arg[0]) == 'e')
				error = error_2_exit(++str_arg);
			else if (str_arg[0][0] == ';' || str_arg[0][0] == '&'
					|| str_arg[0][0] == '|')
				error = error_2_syntax(str_arg);
			else
				error = error_2_cd(str_arg);
			break;
		case 126:
			error = error_126(str_arg);
			break;
		case 127:
			error = error_127(str_arg);
			break;
	}
	write(STDERR_FILENO, error, _strlen(error));

	if (error)
		free(error);
	return (err);

}
