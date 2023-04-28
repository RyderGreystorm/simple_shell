#include "main.h"

/**
 * help_exit - exit info
 * Return: void
 */
void help_exit(void)
{
	char *info = "exit: exit [STATUS]\n\tExits the shell.\n\n\tThe ";

	write(STDOUT_FILENO, info, _strlen(info));
	info = "STATUS argument is the integer used to exit the shell.";
	write(STDOUT_FILENO, info, _strlen(info));
	info = " If no argument is given, the command is interpreted as";
	write(STDOUT_FILENO, info, _strlen(info));
	info = " exit 0.\n";
	write(STDOUT_FILENO, info, _strlen(info));
}
