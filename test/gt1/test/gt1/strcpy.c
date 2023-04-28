#include "main.h"

/**
 * _strcpy - copies string one to string 2
 * @dest: destination string.
 * @src: src string.
 * Return: destination string
 */
char *_strcpy(char *dest, const char *src)
{
	size_t len;

	for (len = 0; src[len] != '\0'; len++)
		dest[len] = src[len];
	dest[len] = '\0';
	return (dest);
}
