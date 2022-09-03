#include "main.h"

/**
 * _memcpy - copies information between void pointers
 * @newptr: destination pointer
 * @ptr: source pointer
 * @size: soze of the new pointer
 * Return: no return
 */

void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int j;

	for (j = 0; j < size; j++)
		char_newptr[j] = char_ptr[j];
}


/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocated
 * @old_size: size in bytes of the allocated space of ptr
 * @new_size: size in bytes of the new memory block
 * Return: ptr
 * if new_size == old_size, return ptr without changes
 * if malloc fails, return NULL
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);
	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);
	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);
	free(ptr);
	return (newptr);
}


/**
 * _reallocdp - reallocates a memory block of a double pointer
 * @ptr: double pointer to the memory previously allocated
 * @old_size: size in byte of the allocated space of ptr
 * @new_size: new size in byte of the new memory block
 * Return: ptr
 * if new_size == old_size, return ptr without changes
 * if malloc fails return NULL
 */

char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int j;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));
	if (new_size == old_size)
		return (ptr);
	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);
	for (j = 0; j < old_size; j++)
		newptr[j] = ptr[j];
	free(ptr);
	return (newptr);
}
