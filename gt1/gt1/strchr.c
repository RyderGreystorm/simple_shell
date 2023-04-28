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
