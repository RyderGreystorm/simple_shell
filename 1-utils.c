#include "main.h"

/**
 * _strlen - finds the length of a string
 * @str: string to find length of
 * Return: lenght of string;
 */

int _strlen(char *str)
{
	int i, len = 0;

	if (str == NULL)
		return (0);

	for (i = 0; str[i] != '\0'; i++)
		len++;
	return (len);
}

/**
 * _strcpy - copies a string from source to destination
 *@des: destination string
 *@src: source string
 * Return: destination string
 */

char *_strcpy(char *des, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		des[i] = src[i];
	des[i] = '\0';
	return (des);
}

/**
 * _strcat - concatenates two strings
 * @des: destination string
 * @src: source string
 * Return: destination string
 */
char *_strcat(char *des, char *src)
{
	int deslen = strlen(des), srclen = strlen(src);
	int i;

	for (i = 0; i < srclen; i++)
	{
	des[deslen + i] = src[i];
	}
	des[deslen + srclen] = '\0';
	return (des);
}

/**
 * _strdup - duplicates a string using malloc
 * @str: string to be duplicated
 * Return: duplicated string
 */

char *_strdup(char *str)
{
	int j = 0, i = 1;
	char *ptr;

	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		i++;
	}
	ptr = malloc((sizeof(char) * i) + 1);

	if (ptr == NULL)
	return (NULL);

	while (j < i)
	{
		ptr[j] = str[j];
		j++;
	}
	ptr[i] = '\0';

	return (ptr);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
