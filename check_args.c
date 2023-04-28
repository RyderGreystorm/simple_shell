#include "main.h"

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
			if (nex && (nex[0] == ';' || nex[0] == '&' ||
						nex[0] == '|'))
				return (handle_error(&args[pos + 1], 2));
		}
	}
	return (0);
}
