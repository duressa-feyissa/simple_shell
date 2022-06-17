#include "shell.h"

/**
 * _realloc - A function that reallocates a memory block
 * @ptr: is a pointer to the memory previously allocated
 * @old_size:  is the size, in bytes, of the allocated space for ptr
 * @new_size:  is the new size, in bytes of the new memory block
 * Return: New allocated memory.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *filler1, *filler2;
	unsigned int i = 0, j = 0;

	if (new_size == old_size)
		return (ptr);

	if (!new_size && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(new_size));

	filler2 = malloc(new_size);
	if (filler2 == NULL)
	{
		return (NULL);
	}

	filler1 = ptr;
	if (new_size < old_size)
	{
		while (i < (new_size))
		{
			filler2[i] = filler1[i];
			i++;
		}
	}
	if (new_size > old_size)
	{
		while (j < (old_size))
		{
			filler2[j] = 0;
			j++;
		}
	}
	free(ptr);
	return (filler2);
}

/**
 * _memcpy - copy memory area
 *
 * @dest: destination memory
 * @src: source memory
 * @n: bytes to copy
 * Return: pointer to the destination memory
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	char *dest_ptr = (char *) dest;
	char *src_ptr = (char *) src;
	unsigned int i;

	for (i = 0; i < n; i++)
		dest_ptr[i] = src_ptr[i];

	return (dest_ptr);
}

/**
 * *_strdup - a function that duplicates a string
 *
 * @s: input string to duplicate
 *
 * Return: NULL if str == NULL
 *         @str
*/
char *_strdup(const char *s)
{
	size_t len;
	char *dup;

	len = _strlen(s);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	_memcpy(dup, s, len + 1);
	return (dup);
}

/**
 * _realloc2 - reallocates a memory block of a double pointer.
 * @ptr: double pointer to the memory previously allocated.
 * @old_size: size, in bytes, of the allocated space of ptr.
 * @new_size: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if new_size == old_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
char **_realloc2(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		newptr[i] = ptr[i];

	free(ptr);

	return (newptr);
}
