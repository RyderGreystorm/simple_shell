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

/**
 * _file_commands - cmd file
 * @path: Path 
 * @ex: Return exec value
 *
 * Return: 127 on failure, malloc fails at -1
 */
int _file_commands(char *path, int *ex)
{
	ssize_t file, fd, x;
	unsigned int size1 = 0;
	unsigned int size2 = 120;
	char *line, **args, **ptr;
	char buffer[120];
	int ret;

	hist = 0;
	file = open(path, O_RDONLY);
	if (file == -1)
	{
		*ex = file_not_open(path);
		return (*ex);
	}
	line = malloc(sizeof(char) * size2);
	if (!line)
		return (-1);
	do {
		fd = read(file, buffer, 119);
		if (fd == 0 && size1 == 0)
			return (*ex);
		buffer[fd] = '\0';
		size1 += fd;
		line = my_realloc(line, size2, size1);
		_strcat(line, buffer);
		size2 = size1;
	} while (fd);
	for (x = 0; line[x] == '\n'; x++)
		line[x] = ' ';
	for (; x < size1; x++)
	{
		if (line[x] == '\n')
		{
			line[x] = ';';
			for (x += 1; x < size1 && line[x] == '\n'; x++)
				line[x] = ' ';
		}
	}
	variable_replacement(&line, ex);
	handle_line(&line, size1);
	args = _strtok(line, " ");
	free(line);
	if (!args)
		return (0);
	if (check_args(args) != 0)
	{
		*ex = 2;
		free_args(args, args);
		return (*ex);
	}
	ptr = args;

	for (x = 0; args[x]; x++)
	{
		if (_strncmp(args[x], ";", 1) == 0)
		{
			free(args[x]);
			args[x] = NULL;
			ret = call_args(args, ptr, ex);
			args = &args[++x];
			x = 0;
		}
	}

	ret = call_args(args, ptr, ex);

	free(ptr);
	return (ret);
}
