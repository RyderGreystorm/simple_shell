#include "main.h"

/**
 * _printf - prints to the stdout
 * @str: string passed to the function
 */

void _printf(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}

/**
 * _strcmp - compares to strings to determine if they are the some
 * @str1: first string
 * @str2: secodn argument
 * Return: 0 if the strings are the same
 */

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(const unsigned char *)str1 - *(const unsigned char *)str2);
}

