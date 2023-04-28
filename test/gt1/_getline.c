#include "main.h"

/**
 * _getline - function of the prototype
 * @ptr: buffer
 * @mem: ptr size.
 * @stream: read here.
 *
 * Return: bytes read.
 */
ssize_t _getline(char **ptr, size_t *mem, FILE *stream)
{
	static ssize_t input;
	ssize_t ret;
	char c = 'x', *buffer;
	int r;

	if (stream == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;
	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
		return (-1);
	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (r == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= 120)
			buffer = my_realloc(buffer, input, input + 1);
		buffer[input] = c;
		input++;
	}
	buffer[input] = '\0';
	_lineptr(ptr, mem, buffer, input);
	ret = input;
	if (r != 0)
		input = 0;
	return (ret);
}
