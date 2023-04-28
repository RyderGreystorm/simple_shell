#include "main.h"

/**
 * handle_line - line handler
 * @buffer: A pointer buffer.
 * @read: The length of buffer.
 */
void handle_line(char **buffer, ssize_t read)
{
	char *line1, *line2;
	char prev, curr, next;
	size_t b, j;
	ssize_t line_len;

	line_len = get_new_len(*buffer);
	if (line_len == read - 1)
		return;
	line2 = malloc(line_len + 1);
	if (!line2)
		return;
	j = 0;
	line1 = *buffer;
	for (b = 0; line1[b]; b++)
	{
		curr = line1[b];
		next = line1[b + 1];
		if (b != 0)
		{
			prev = line1[b - 1];
			if (curr == ';')
			{
				if (next == ';' && prev != ' ' && prev != ';')
				{
					line2[j++] = ' ';
					line2[j++] = ';';
					continue;
				}
				else if (prev == ';' && next != ' ')
				{
					line2[j++] = ';';
					line2[j++] = ' ';
					continue;
				}
				if (prev != ' ')
					line2[j++] = ' ';
				line2[j++] = ';';
				if (next != ' ')
					line2[j++] = ' ';
				continue;
			}
			else if (curr == '&')
			{
				if (next == '&' && prev != ' ')
					line2[j++] = ' ';
				else if (prev == '&' && next != ' ')
				{
					line2[j++] = '&';
					line2[j++] = ' ';
					continue;
				}
			}
			else if (curr == '|')
			{
				if (next == '|' && prev != ' ')
					line2[j++]  = ' ';
				else if (prev == '|' && next != ' ')
				{
					line2[j++] = '|';
					line2[j++] = ' ';
					continue;
				}
			}
		}
		else if (curr == ';')
		{
			if (b != 0 && line1[b - 1] != ' ')
				line2[j++] = ' ';
			line2[j++] = ';';
			if (next != ' ' && next != ';')
				line2[j++] = ' ';
			continue;
		}
		line2[j++] = line1[b];
	}
	line2[j] = '\0';

	free(*buffer);
	*buffer = line2;
}

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
/**
 * logical_ops - handles logical operations
 * @buffer: pointer to buffer.
 * @line_len: pointer to line_len
 */
void logical_ops(char *buffer, ssize_t *line_len)
{
	char prev, curr, next;

	prev = *(buffer - 1);
	curr = *buffer;
	next = *(buffer + 1);

	if (curr == '&')
	{
		if (next == '&' && prev != ' ')
			(*line_len)++;
		else if (prev == '&' && next != ' ')
			(*line_len)++;
	}
	else if (curr == '|')
	{
		if (next == '|' && prev != ' ')
			(*line_len)++;
		else if (prev == '|' && next != ' ')
			(*line_len)++;
	}
}
