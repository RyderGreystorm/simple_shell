#include "main.h"


/**
 * get_pid - get pid
 * Description: handles the current process pid
 * Return: current pid on successs,null on failure
 */
char *get_pid(void)
{
	size_t num1 = 0;
	char *buff;
	ssize_t fd;

	fd = open("/proc/self/stat", O_RDONLY);
	if (fd == -1)
	{
		perror("fd failed");
		return (NULL);
	}
	buff = malloc(120);
	if (!buff)
	{
		close(fd);
		return (NULL);
	}
	read(fd, buff, 120);
	while (buff[num1] != ' ')
		num1++;
	buff[num1] = '\0';

	close(fd);
	return (buff);
}
