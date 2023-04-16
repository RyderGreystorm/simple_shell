#include "main.h"

/**
 * exec - hels in executing commands from the binary directory
 * @argv: takes the first argument which is file name from what is read
 */

void exec(char **argv)
{
	char *cmd = NULL; /*will be used to store filename*/
	char *newPath = NULL;

	if (argv != NULL)
	{
	/*getting the filename which is argv[o]*/
		cmd = argv[0];

	/*create the new path*/
		newPath = get_path(cmd);
	/*using execve to execute the command*/
		if (execve(newPath, argv, NULL ) == -1)
			perror("Error: ");
	}
}
