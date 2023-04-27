#include "main.h"
/**
 * get_path - get the path of our file
 * @cmd: command being executed by user
 * Return: the file path
 */

char *get_path(char *cmd)
{
	char *path = NULL, *pathcp = NULL, *p_token =  NULL, *f_path = NULL;
	int cmd_len = _strlen(cmd), dir_len = 0;
	struct stat buff;

	path = getenv("PATH");
	if (path != NULL)
	{
		pathcp = _strdup(path);
		if (!pathcp)
			return (NULL);
		p_token = strtok(pathcp, ":");
		while (p_token)
		{
			dir_len = _strlen(p_token);
			f_path = malloc(sizeof(char) * (cmd_len + dir_len + 2));
			if (!f_path)
			{
				free(pathcp);
				return (NULL);
			}
			_strcpy(f_path, p_token);
			_strcat(f_path, "/");
			_strcat(f_path, cmd);
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
