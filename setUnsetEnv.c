#include "main.h"

/**
 * setEnv - used to set teh value of an environment variable
 * @args: checks if both value and variable are present in the args buffer
 */

void setEnv(char **args)
{
	if (!args[1] || !args[2])
	{
		perror("Usage: setenv VARIABLE VALUE\n");
		return;
	}
	if (setenv(args[1], args[2], 1) != 0)
	{
		perror("setenv");
	}
}

/**
 * unsetEnv - unsets the value and variable of an enviroment
 *@args: arguments in buffer
 */

void unsetEnv(char **args)
{
	if (!args[1])
	{
		perror("Usage: unsetenv VARIABLE\n");
		return;
	}
	if (unsetenv(args[1]) != 0)
		perror("unsetenv");
}
