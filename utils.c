#include "main.h"

/**
 * _strlen - finds the length of a string
 * @str: string to find length of
 * Return: lenght of string;
 */

int _strlen(char *str)
{
	int i, len;

	for (i = 0; str[i] != '\0'; i++)
		len++;
	return (len);
}

/**
 * _strcpy - copies a string from source to destination
 * des: destination string
 * src: source string
 * Return: destination string
 */

void _strcpy(char *des, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		des[i] = src[i];
}
