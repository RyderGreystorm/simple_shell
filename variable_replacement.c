#include "main.h"

/**
 * replace_variables - handles variable replacements in the shell
 * @str: line read from the stdin
 * Return: string from the stdin
 */

char *replace_variables(char *str)
{
	char *buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	char *retBuffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	int i = 0, j = 0;
	pid_t pid = getpid();
	int exit_status = 0;
	char *path = getenv("PATH");

	while (str[i] != '\0')
	{
	if (str[i] == '$' && str[i + 1] == '?')
	{
		snprintf(buffer, BUFFER_SIZE, "%d", exit_status);
		_strcat(retBuffer, buffer);
		j += _strlen(buffer);
		i += 2;
	}
	else if (str[i] == '$' && str[i + 1] == '$')
	{
		snprintf(buffer, BUFFER_SIZE, "%d", pid);
		_strcat(retBuffer, buffer);
		j += _strlen(buffer);
		i += 2;
	}
	else if (strncmp(&str[i], "$PATH", 5) == 0)
	{
		_strcat(retBuffer, path);
		j += _strlen(path);
		i += 5;
	}
	else
	retBuffer[j++] = str[i++];
	}

	retBuffer[j] = '\0';

	free(buffer);

	return (retBuffer);
}
