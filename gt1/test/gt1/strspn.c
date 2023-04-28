#include "main.h"

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
