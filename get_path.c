#include "main.h"
/**
 * get_path - get the path of our file
 * @cmd: command being executed by user
 * Return: the file path
 */

char *get_path(char *cmd)
{
	char *path, *pathcp, *p_token, *f_path;
	int cmd_len, dir_len;
	struct stat buff;

	path = getenv("PATH");
	if (path != NULL)
	{
		pathcp = _strdup(path);
		cmd_len = _strlen(cmd);
		p_token = strtok(pathcp, ":");
		while (p_token)
		{
			dir_len = _strlen(p_token); /*the length of each token*/
			f_path = malloc(sizeof(char) * (cmd_len + dir_len + 2));
			_strcpy(f_path, p_token);
			_strcat(f_path, "/");
			_strcat(f_path, cmd);
			_strcat(f_path, "\0");
			if (stat(f_path, &buff) == 0)
			{

				free(pathcp); /*free the pathcp*/
				return (f_path);
			}
			else
			{
				free(f_path);
				p_token = strtok(NULL, ":");
			}
		}
		free(pathcp);
		if (stat(cmd, &buff) == 0)
			return (cmd);
		return (NULL);
	}
	return (NULL);
}
