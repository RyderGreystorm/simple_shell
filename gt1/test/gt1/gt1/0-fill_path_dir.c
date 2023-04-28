#include "main.h"

/**
 * fill_path_dir - path
 * @path: path from getenv.
 * Return: path copy.
 */
char *fill_path_dir(char *path)
{
	int index, length = 0;
	char *path_copy, *pwd;

	pwd = *(_getenv("PWD")) + 4;
	for (index = 0; path[index]; index++)
	{
		if (path[index] == ':')
		{
			if (path[index + 1] == ':' || index == 0 || path[index + 1] == '\0')
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
	for (index = 0; path[index]; index++)
	{
		if (path[index] == ':')
		{
			if (index == 0)
			{
				_strcat(path_copy, pwd);
				_strcat(path_copy, ":");
			}
			else if (path[index + 1] == ':' || path[index + 1] == '\0')
			{
				_strcat(path_copy, ":");
				_strcat(path_copy, pwd);
			}
			else
				_strcat(path_copy, ":");
		}
		else
		{
			_strncat(path_copy, &path[index], 1);
		}
	}
	return (path_copy);
}
