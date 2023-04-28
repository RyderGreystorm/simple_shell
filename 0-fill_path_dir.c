#include "main.h"

/**
 * fill_path_dir - path
 * @path: path from getenv.
 * Return: path copy.
 */
char *fill_path_dir(char *path)
{
	int x, length = 0;
	char *path_copy, *pwd;

	pwd = *(_getenv("PWD")) + 4;
	for (x = 0; path[x]; x++)
	{
		if (path[x] == ':')
		{
			if (path[x + 1] == ':' || x == 0 || path[x + 1] == '\0')
				length += _strlen(pwd) + 1;
			else
				length++;
		}
		else
			length++;
	}
	path_copy = malloc(sizeof(char) * (length + 1));
	if (!path_copy)
		return (NULL);
	path_copy[0] = '\0';
	for (x = 0; path[x]; x++)
	{
		if (path[x] == ':')
		{
			if (x == 0)
			{
				_strcat(path_copy, pwd);
				_strcat(path_copy, ":");
			}
			else if (path[x + 1] == ':' || path[x + 1] == '\0')
			{
				_strcat(path_copy, ":");
				_strcat(path_copy, pwd);
			}
			else
				_strcat(path_copy, ":");
		}
		else
		{
			_strncat(path_copy, &path[x], 1);
		}
	}
	return (path_copy);
}
