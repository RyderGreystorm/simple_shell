include "main.h"

/**
 * help_cd - cd helper
 * Return: void
 */
void help_cd(void)
{
	char *info = "cd: cd [DIRECTORY]\n\tChanges the current directory of the";

	write(STDOUT_FILENO, info, _strlen(info));
	info = " process to DIRECTORY.\n\n\tIf no argument is given, the ";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "command is interpreted as cd $HOME. If the argument '-' is";
	write(STDOUT_FILENO, info, _strlen(info));
	info = " given, the command is interpreted as cd $OLDPWD.\n\n";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "\tThe environment variables PWD and OLDPWD are updated ";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "after a change of directory.\n";
	write(STDOUT_FILENO, info, _strlen(info));
}
