#include "main.h"

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
