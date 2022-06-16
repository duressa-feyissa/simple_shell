#include "_string.h"

/**
 * _strdup - duplicates a string
 *
 * @s: the given string
 * Return: pointer to the duplicate
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
 * _strlen - length of a string
 *
 * @s: the given string
 * Return: length of the string string
 */
size_t _strlen(const char *s)
{
	size_t i;

	for (i = 0; s[i]; i++)
		;

	return (i);
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
 * _strcat - concatenates two strings
 *
 * @dest: the destination string
 * @src: string to concatenates
 * Return: pointer to the resulting string
 */
char *_strcat(char *dest, const char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - Function that compares two strings.
 * @s1: type str compared
 * @s2: type str compared
 * Return: Always 0.
 */
int _strcmp(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}
