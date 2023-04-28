#include "main.h"

/**
 * _lineptr - pointer to line of memory
 * @ptr: buffer containing line of memory
 * @mem: size of line of memory
 * @buffer: line pointer.
 * @bytes: buffer size
 */
void _lineptr(char **ptr, size_t *mem, char *buffer, size_t bytes)
{
	if (*ptr == NULL)
	{
		if (bytes > 120)
			*mem = bytes;
		else
			*mem = 120;
		*ptr = buffer;
	}
	else if (*mem < bytes)
	{
		if (bytes > 120)
			*mem = bytes;
		else
			*mem = 120;
		*ptr = buffer;
	}
	else
	{
		_strcpy(*ptr, buffer);
		free(buffer);
	}
}
