#include "main.h"

char *err_name;
int hist;
aliases_t *aliases;
/**
 * free_args - free arguments read
 * @args: cmd buffer with null terminator
 * @ptr: buffer pointer.
 */
void free_args(char **args, char **ptr)
{
	size_t num1;

	for (num1 = 0; args[num1] || args[num1 + 1]; num1++)
		free(args[num1]);

	free(ptr);
}

/**
 * get_pid - get pid
 * Description: handles the current process pid
 * Return: current pid on successs,null on failure
 */
char *get_pid(void)
{
	size_t num1 = 0;
	char *buff;
	ssize_t fd;

	fd = open("/proc/self/stat", O_RDONLY);
	if (fd == -1)
	{
		perror("Cant read fd");
		return (NULL);
	}
	buff = malloc(120);
	if (!buff)
	{
		close(fd);
		return (NULL);
	}
	read(fd, buff, 120);
	while (buff[num1] != ' ')
		num1++;
	buff[num1] = '\0';

	close(fd);
	return (buff);
}

/**
 * get_env_value - env value
 * @needle: var in search for
 * @haystack: var length
 *
 * Return: value fo the replace vairable or empty string
 */
char *get_env_value(char *needle, int haystack)
{
	char **var_ptr;
	char *replace = NULL, *tmp, *var;

	var = malloc(haystack + 1);
	if (!var)
		return (NULL);
	var[0] = '\0';
	_strncat(var, needle, haystack);

	var_ptr = _getenv(var);
	free(var_ptr);
	if (var)
	{
		tmp = *var_ptr;
		while (*tmp != '=')
			tmp++;
		tmp++;
		replace = malloc(_strlen(tmp) + 1);
		if (replace)
			_strcpy(replace, tmp);
	}

	return (replace);
}

/**
 * variable_replacement - varaible replace
 * @buff: pointer to args
 * @exe: A pointer to last cmd arg return value
 *
 */
void variable_replacement(char **buff, int *exe)
{
	int num1, num2 = 0, len;
	char *replace = NULL, *line1 = NULL, *line2;

	line1 = *buff;
	for (num1 = 0; line1[num1]; num1++)
	{
		if (line1[num1] == '$' && line1[num1 + 1] &&
				line1[num1 + 1] != ' ')
		{
			if (line1[num1 + 1] == '$')
			{
				replace = get_pid();
				num2 = num1 + 2;
			}
			else if (line1[num1 + 1] == '?')
			{
				replace = _itoa(*exe);
				num2 = num1 + 2;
			}
			else if (line1[num1 + 1])
			{
				/* extract the variable name to search for */
				for (num2 = num1 + 1; line1[num2] &&
						line1[num2] != '$' &&
						line1[num2] != ' '; num2++)
					;
				len = num2 - (num1 + 1);
				replace = get_env_value(&line1[num1 + 1], len);
			}
			line2 = malloc(num1 + _strlen(replace)
					  + _strlen(&line1[num2]) + 1);
			if (!buff)
				return;
			line2[0] = '\0';
			_strncat(line2, line1, num1);
			if (replace)
			{
				_strcat(line2, replace);
				free(replace);
				replace = NULL;
			}
			_strcat(line2, &line1[num2]);
			free(line1);
			*buff = line2;
			line1 = line2;
			num1 = -1;
		}
	}
}
