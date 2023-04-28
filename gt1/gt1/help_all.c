#include "main.h"

/**
 * help_all - terminal info on cmds
 */
void help_all(void)
{
	char *info = "Shellby\nThese shell commands are defined internally.\n";

	write(STDOUT_FILENO, info, _strlen(info));
	info = "Type 'help' to see this list.\nType 'help name' to find ";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "out more about the function 'name'.\n\n  alias   \t";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "alias [NAME[='VALUE'] ...]\n  cd    \tcd   ";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "[DIRECTORY]\n  exit    \texit [STATUS]\n  env     \tenv";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "\n  setenv  \tsetenv [VARIABLE] [VALUE]\n  unsetenv\t";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "unsetenv [VARIABLE]\n";
	write(STDOUT_FILENO, info, _strlen(info));
}
