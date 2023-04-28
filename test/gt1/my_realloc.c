#include "main.h"


/**
 * my_realloc - reallocates memory to the bufer
 * @ptr: A pointer to the memory previously allocated.
 * @size1: The size in bytes of the allocated space for pointer.
 * @size2: The size in bytes for the new memory block.
 * Return: pointer to the newly allocated memory
 */
void *my_realloc(void *ptr, unsigned int size1, unsigned int size2)
{
	void *mem;
	char *ptr_copy, *filler;
	unsigned int index;

	if (size2 == size1)
		return (ptr);
	if (ptr == NULL)
	{
		mem = malloc(size2);
		if (mem == NULL)
			return (NULL);

		return (mem);
	}
	if (size2 == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	ptr_copy = ptr;
	mem = malloc(sizeof(*ptr_copy) * size2);
	if (mem == NULL)
	{
		free(ptr);
		return (NULL);
	}
	filler = mem;
	for (index = 0; index < size1 && index < size2; index++)
		filler[index] = *ptr_copy++;
	free(ptr);
	return (mem);
}
