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


/**
 * handle_error - error handling
 * @str_arg: arg params.
 * @err: error.
 * Return: value of error.
 */
int handle_error(char **str_arg, int err)
{
	char *error;

	switch (err)
	{
	case -1:
		error = error_env(str_arg);
		break;
	case 1:
		error = error_1(str_arg);
		break;
	case 2:
		if (*(str_arg[0]) == 'e')
			error = error_2_exit(++str_arg);
		else if (str_arg[0][0] == ';' || str_arg[0][0] == '&' || str_arg[0][0] == '|')
			error = error_2_syntax(str_arg);
		else
			error = error_2_cd(str_arg);
		break;
	case 126:
		error = error_126(str_arg);
		break;
	case 127:
		error = error_127(str_arg);
		break;
	}
	write(STDERR_FILENO, error, _strlen(error));

	if (error)
		free(error);
	return (err);

}
