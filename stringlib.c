#include "main.h"


/**
 * _strlen - ffinds lenght of string
 * @s: string params
 * Return: length of string
 */
int _strlen(const char *str)
{
	int len = 0;

	if (!str)
		return (len);
	for (len = 0; str[len]; len++)
		;
	return (len);
}

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

/**
 * _strcat - concatenates string one to string two
 * @dest: destination string
 * @src: source string.
 * Return: destination string.
 */
char *_strcat(char *dest, const char *src)
{
	char *tmpdes;
	const char *tmpsrc;

	tmpdes = dest;
	tmpsrc =  src;

	while (*tmpdes != '\0')
		tmpdes++;

	while (*tmpsrc != '\0')
		*tmpdes++ = *tmpsrc++;
	*tmpdes = '\0';
	return (dest);
}

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
