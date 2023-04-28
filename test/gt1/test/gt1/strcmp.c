#include "main.h"

/**
 * _strcmp - fcompares two strings
 * @str1: str 1
 * @str2: str2
 * Return: 0 if they match
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);

	return (0);
}
