#include "main.h"

/**
 * _strncat - concatenates n bytes of string from source to destination
 * @dest: destination string.
 * @src: source string.
 * @bytes: bytes taken from source
 * Return: destination string.
 */
char *_strncat(char *dest, const char *src, size_t bytes)
{
	size_t len = _strlen(dest);
	size_t i;

	for (i = 0; i < bytes && src[i] != '\0'; i++)
		dest[len + i] = src[i];
	dest[len + i] = '\0';

	return (dest);
}
