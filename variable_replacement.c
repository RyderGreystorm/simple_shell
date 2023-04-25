#include "main.h"

/**
 * replace_variables - handles variable replacements in the shell
 * @str: line read from the stdin
 * Return: string from the stdin
 */

char *replace_variables(char *str)
{
	char *output = malloc(MAX_INPUT_SIZE * sizeof(char));
	char *var_value;
	int i = 0, j = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			i++;
			if (str[i] == '?')
			{
				forkStatus();
				var_value = malloc(sizeof(char) * 4);

			}
			else if (str[i] == '$')
			{
				pid_t pidd = getpid();

				var_value = malloc(sizeof(char) * 16);
				printf("%d\n", pidd);
			}
			else
			{
				continue;
			}
		}
		else
		{
			output[j] = str[i];
			i++;
			j++;
			continue;
		}
		/**Append variable value to output string*/
		strcat(output, var_value);
		j += strlen(var_value);
		free(var_value);
	}
	return (output);
}
