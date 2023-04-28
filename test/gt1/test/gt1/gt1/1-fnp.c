#include "main.h"

/**
 * file_not_open - file not open
 * @path: path.
 * Return: 127.
 */

int file_not_open(char *path)
{
	char *error, *str_his;
	int lenght;

	str_his = _itoa(hist);
	if (!str_his)
		return (127);

	lenght = _strlen(err_name) + _strlen(str_his) + _strlen(path) + 16;
	error = malloc(sizeof(char) * (lenght + 1));
	if (!error)
	{
		free(str_his);
		return (127);
	}

	_strcpy(error, err_name);
	_strcat(error, ": ");
	_strcat(error, str_his);
	_strcat(error, ": Can't open ");
	_strcat(error, path);
	_strcat(error, "\n");

	free(str_his);
	write(STDERR_FILENO, error, lenght);
	free(error);
	return (127);
}
