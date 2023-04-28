#include "main.h"

/**
 * _itoa - itoa func
 * @num_len: int.
 * Return: converted string
 */
char *_itoa(int num_len)
{
	char *buff;
	int len_num = num_length(num_len);
	unsigned int num1;

	buff = malloc(sizeof(char) * (len_num + 1));
	if (!buff)
		return (NULL);

	buff[len_num] = '\0';

	if (num_len < 0)
	{
		num1 = num_len * -1;
		buff[0] = '-';
	}
	else
	{
		num1 = num_len;
	}

	len_num--;
	do {
		buff[len_num] = (num1 % 10) + '0';
		num1 /= 10;
		len_num--;
	} while (num1 > 0);

	return (buff);
}
