#include "main.h"

/**
 * num_length - numlength
 * @num_len: nums
 * Return: len
 */
int num_length(int num_len)
{
	unsigned int num1;
	int len = 1;

	if (num_len < 0)
	{
		len++;
		num1 = num_len * -1;
	}
	else
	{
		num1 = num_len;
	}
	while (num1 > 9)
	{
		len++;
		num1 /= 10;
	}

	return (len);
}
