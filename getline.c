#include "main.h"

/**
 * get_input - reads what has been type in the stdin
 * Return: line read
 */

char *get_input(void)
{
	static char buf[1024];
	static int buf_pos;
	static int buf_len;
	char *ret = NULL;
	int i = 0;
	int j = 0;
	char c;

	while (1)
	{
		if (buf_pos >= buf_len)
		{
			buf_len = read(STDIN_FILENO, buf, sizeof(buf));
			buf_pos = 0;
			if (buf_len <= 0 || buf == NULL)
			{
				perror("Exit");
				exit(EXIT_FAILURE);
			}
		}

		c = buf[buf_pos++];
		if (c == '\n')
		{
			ret = (char *) malloc(i + 1);
			if (ret == NULL)
			{
				return (NULL);
			}
			for (j = 0; j < i; j++)
			{
				ret[j] = buf[j];
			}
			ret[i] = c;
			ret[i + 1] = '\0';
			return (ret);
		}
		buf[i++] = c;
	}
}
