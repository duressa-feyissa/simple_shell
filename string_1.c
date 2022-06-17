#include "shell.h"

/**
 * _strlen - A function that returns the length of a string.
 * @s: The integer parameter.
 *
 * Return: The length of string passed
 */
int _strlen(const char *s)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

/**
 * _strcpy - A function that prints half of a string.
 * @src: The pointer to the destination.
 * @dest: The string to be copied.
 *
 * Return: The pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';

	return (dest);
}

/**
 * _strncpy - A function that prints half of a string.
 * @src: The pointer to the destination.
 * @dest: The string to be copied.
 * @n: number of string to be copied
 * Return: The pointer to dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while ((i < n) && *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}

	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}

/**
 * _strcat - A function that concatenates two strings.
 * @src: The pointer to the destination.
 * @dest: The string to be copied.
 *
 * Return: The pointer to dest.
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (*(dest + i))
	{
		i++;
	}

	j = 0;
	while (*(src + j))
	{
		*(dest + i) = *(src + j);
		i++;
		j++;
	}
	*(dest + i) = '\0';

	return (dest);
}

/**
 * _strncat - A function that concatenates two strings.
 * @src: The pointer to the destination.
 * @dest: The string to be copied.
 * @n: Number of string to be copied
 * Return: The pointer to dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	i = 0;
	while (*(dest + i))
	{
		i++;
	}

	j = 0;
	while ((j < n) && *(src + j))
	{
		*(dest + i) = *(src + j);
		i++;
		j++;
	}

	return (dest);
}
