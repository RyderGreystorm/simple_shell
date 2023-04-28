#include "main.h"

/**
 * get_path_dir - dir path finder
 * @path: path
 * Return: pinter to node.
 */
lists_t *get_path_dir(char *path)
{
	int index;
	char **dirs, *path_copy;
	lists_t *head = NULL;

	path_copy = fill_path_dir(path);
	if (!path_copy)
		return (NULL);
	dirs = _strtok(path_copy, ":");
	free(path_copy);
	if (!dirs)
		return (NULL);

	for (index = 0; dirs[index]; index++)
	{
		if (add_node_end(&head, dirs[index]) == NULL)
		{
			free_list(head);
			free(dirs);
			return (NULL);
		}
	}

	free(dirs);

	return (head);
}
