#include "main.h"

/**
 * variable_replacement - varaible replace
 * @buff: pointer to args
 * @exe: A pointer to last cmd arg return value
 *
 */
void variable_replacement(char **buff, int *exe)
{
	int num1, num2 = 0, len;
	char *replace = NULL, *buff1 = NULL, *buff2;

	buff1 = *buff;
	for (num1 = 0; buff1[num1]; num1++)
	{
		if (buff1[num1] == '$' && buff1[num1 + 1] &&
				buff1[num1 + 1] != ' ')
		{
			if (buff1[num1 + 1] == '$')
			{
				replace = get_pid();
				num2 = num1 + 2;
			}
			else if (buff1[num1 + 1] == '?')
			{
				replace = _itoa(*exe);
				num2 = num1 + 2;
			}
			else if (buff1[num1 + 1])
			{
				/* extract the variable name to search for */
				for (num2 = num1 + 1; buff1[num2] &&
						buff1[num2] != '$' &&
						buff1[num2] != ' '; num2++)
					;
				len = num2 - (num1 + 1);
				replace = get_env_value(&buff1[num1 + 1], len);
			}
			buff2 = malloc(num1 + _strlen(replace)
					  + _strlen(&buff1[num2]) + 1);
			if (!buff)
				return;
			buff2[0] = '\0';
			_strncat(buff2, buff1, num1);
			if (replace)
			{
				_strcat(buff2, replace);
				free(replace);
				replace = NULL;
			}
			_strcat(buff2, &buff1[num2]);
			free(buff1);
			*buff = buff2;
			buff1 = buff2;
			num1 = -1;
		}
	}
}
