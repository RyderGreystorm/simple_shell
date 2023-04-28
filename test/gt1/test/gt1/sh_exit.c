#include "main.h"

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
			if (l <= len_of_int && args[0][l] >= '0'
					&& args[0][l] <= '9')
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
