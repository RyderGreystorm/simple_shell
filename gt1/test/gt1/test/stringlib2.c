#include "main.h"


/**
 * _strchr - finds the first occurrence of a character in string
 * @needle: searched string.
 * @haystack: haystack.
 * Return: pointer to the first occurence of s
 */
char *_strchr(char *needle, char haystack)
{
	int index;

	for (index = 0; needle[index]; index++)
	{
		if (needle[index] == haystack)
			return (needle + index);
	}

	return (NULL);
}

/**
 * _strspn - finds lend of sting in a specied segment
 * @str1: searched
 * @str2: buffer to measure from
 * Return: The number of bytes
 */
int _strspn(char *str1, char *str2)
{
	int bytes = 0;
	int i;

	while (*str1)
	{
		for (i = 0; str2[i]; i++)
		{
			if (*str1 == str2[i])
			{
				bytes++;
				break;
			}
		}
		str1++;
	}
	return (bytes);
}

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
