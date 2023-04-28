#include "main.h"

/**
 * _strncmp - compares n bytes of strng to another string
 * @str1: str1
 * @str2:str2
 * @bytes: first bytes of the strings to compare.
 * Return: 0 on match
 */
int _strncmp(const char *str1, const char *str2, size_t bytes)
{
	size_t l;

	for (l = 0; str1[l] && str2[l] && l < bytes; l++)
	{
		if (str1[l] > str2[l])
			return (str1[l] - str2[l]);
		else if (str1[l] < str2[l])
			return (str1[l] - str2[l]);
	}
	if (l == bytes)
		return (0);
	else
		return (-15);
}
