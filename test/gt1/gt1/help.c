#include "main.h"

/**
 * help_help - help info
 * Return: void
 */
void help_help(void)
{
	char *info = "help: help\n\tSee all possible Shellby builtin commands.\n";

	write(STDOUT_FILENO, info, _strlen(info));
	info = "\n      help [BUILTIN NAME]\n\tSee specific information on each ";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "builtin command.\n";
	write(STDOUT_FILENO, info, _strlen(info));
}

