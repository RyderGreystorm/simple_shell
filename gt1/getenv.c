#include "main.h"

/**
 * _getenv - get envrioment variable
 * @var: env of interes.
 * Return: env on sucess and null on failure
 */
char **_getenv(const char *var)
{
	int i, len;

	len = _strlen(var);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(var, environ[i], len) == 0)
			return (&environ[i]);
	}

	return (NULL);
}
