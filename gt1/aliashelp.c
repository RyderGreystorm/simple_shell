#include "main.h"
/**
 * help_alias - alias assistance
 */
void help_alias(void)
{
	char *info = "alias: alias [NAME[='VALUE'] ...]\n\tHandles aliases.\n";

	write(STDOUT_FILENO, info, _strlen(info));
	info = "\n\talias: Prints a list of all aliases, one per line, in ";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "the format NAME='VALUE'.\n\talias name [name2 ...]:prints";
	write(STDOUT_FILENO, info, _strlen(info));
	info = " the aliases name, name2, etc. one per line, in the ";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "form NAME='VALUE'.\n\talias NAME='VALUE' [...]: Defines";
	write(STDOUT_FILENO, info, _strlen(info));
	info = " an alias for each NAME whose VALUE is given. If NAME ";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "is already an alias, replace its value with VALUE.\n";
	write(STDOUT_FILENO, info, _strlen(info));
}

