#include "main.h"

/**
 * get_new_len - get length
 * @buffer: buffer of interest.
 * Return: The new length of the buffer.
 */

ssize_t get_new_len(char *buffer)
{
	size_t b;
	ssize_t line_len = 0;
	char curr, next;

	for (b = 0; buffer[b]; b++)
	{
		curr = buffer[b];
		next = buffer[b + 1];
		if (curr == '#')
		{
			if (b == 0 || buffer[b - 1] == ' ')
			{
				buffer[b] = '\0';
				break;
			}
		}
		else if (b != 0)
		{
			if (curr == ';')
			{
				if (next == ';' && buffer[b - 1] != ' ' && buffer[b - 1] != ';')
				{
					line_len += 2;
					continue;
				}
				else if (buffer[b - 1] == ';' && next != ' ')
				{
					line_len += 2;
					continue;
				}
				if (buffer[b - 1] != ' ')
					line_len++;
				if (next != ' ')
					line_len++;
			}
			else
				logical_ops(&buffer[b], &line_len);
		}
		else if (curr == ';')
		{
			if (b != 0 && buffer[b - 1] != ' ')
				line_len++;
			if (next != ' ' && next != ';')
				line_len++;
		}
		line_len++;
	}
	return (line_len);
}
