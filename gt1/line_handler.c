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
