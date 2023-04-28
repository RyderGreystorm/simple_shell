#include "main.h"

/**
 * logical_ops - handles logical operations
 * @buffer: pointer to buffer.
 * @line_len: pointer to line_len
 */
void logical_ops(char *buffer, ssize_t *_len)
{
	char prev, curr, next;

	prev = *(buffer - 1);
	curr = *buffer;
	next = *(buffer + 1);

	if (curr == '&')
	{
		if (next == '&' && prev != ' ')
			(*_len)++;
		else if (prev == '&' && next != ' ')
			(*_len)++;
	}
	else if (curr == '|')
	{
		if (next == '|' && prev != ' ')
			(*_len)++;
		else if (prev == '|' && next != ' ')
			(*_len)++;
	}
}
