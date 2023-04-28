#include "main.h"

/**
 * get_args - reads args
 * @buffer: buffer
 * @exe: points to str returned
 * Return: args readfrom cmd line
 */
char *get_args(char *buffer, int *exe)
{
	size_t size = 0;
	ssize_t fd;
	char *prompt = "FavShell$ ";

	if (buffer)
		free(buffer);

	fd = _getline(&buffer, &size, STDIN_FILENO);
	if (fd == -1)
		return (NULL);
	if (fd == 1)
	{
		hist++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, 6);
		return (get_args(buffer, exe));
	}

	buffer[fd - 1] = '\0';
	variable_replacement(&buffer, exe);
	handle_line(&buffer, fd);

	return (buffer);
}
