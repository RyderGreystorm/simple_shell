#include "main.h"


/**
 * _realloc - reallocates memory to the bufer
 * @ptr: A pointer to the memory previously allocated.
 * @size1: The size in bytes of the allocated space for pointer.
 * @size2: The size in bytes for the new memory block.
 *
 * Return: If size2 == size1 - ptr.
 *         If size2 == 0 and ptr is not NULL - NULL.
 *         Otherwise - a pointer to the reallocated memory block.
 */
void *my_realloc(void *ptr, unsigned int size1, unsigned int size2)
{
	void *mem;
	char *ptr_copy, *filler;
	unsigned int index;

	if (size2 == size1)
		return (ptr);

	if (ptr == NULL)
	{
		mem = malloc(size2);
		if (mem == NULL)
			return (NULL);

		return (mem);
	}

	if (size2 == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	ptr_copy = ptr;
	mem = malloc(sizeof(*ptr_copy) * size2);
	if (mem == NULL)
	{
		free(ptr);
		return (NULL);
	}

	filler = mem;

	for (index = 0; index < size1 && index < size2; index++)
		filler[index] = *ptr_copy++;

	free(ptr);
	return (mem);
}

/**
 * _lineptr - pointer to line of memory
 * @ptr: buffer containing line of memory
 * @m: size of line of memory
 * @buffer: line pointer.
 * @b: buffer size
 */
void _lineptr(char **ptr, size_t *m, char *buffer, size_t b)
{
	if (*ptr == NULL)
	{
		if (b > 120)
			*m = b;
		else
			*m = 120;
		*ptr = buffer;
	}
	else if (*m < b)
	{
		if (b > 120)
			*m = b;
		else
			*m = 120;
		*ptr = buffer;
	}
	else
	{
		_strcpy(*ptr, buffer);
		free(buffer);
	}
}

/**
 * _getline - function of the prototype
 * @ptr: buffer
 * @m: ptr size.
 * @stream: read here.
 *
 * Return: bytes read.
 */
ssize_t _getline(char **ptr, size_t *m, FILE *stream)
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

	_lineptr(ptr, m, buffer, input);

	ret = input;
	if (r != 0)
		input = 0;
	return (ret);
}
