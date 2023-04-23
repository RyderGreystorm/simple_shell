#include "main.h"

/**
 * chdirectory - it changes the current working directory of the shell.
 * @argv: parameter used to pass the command-line arguments to the function.
 */

void chdirectory(char **argv)
{
	char pwd[1024];
	char *directory = NULL;
	/*Check for directroy argument*/
	if (argv[1] != NULL)
		directory = argv[1];
	else
	{
		directory = getenv("HOME");
		if (directory == NULL)
			return;
	}

	/*  "cd -" handling*/
	if (directory && strcmp(directory, "-") == 0)
	{
		directory = getenv("OLDPWD");
		if (directory == NULL)
		{
			perror("Directory");
			return;
		}
		printf("%s\n", directory);
	}
	if (chdir(directory) != 0)
	{
		perror("cd");
		return;
	}
	if (getcwd(pwd, sizeof(pwd)) != NULL)
		setenv("PWD", pwd, 1);
	else
	{
		perror("getcwd");
		return;
	}
	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", getcwd(NULL, 0), 1);
}
