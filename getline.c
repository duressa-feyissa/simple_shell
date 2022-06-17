#include "shell.h"
#include "util.h"

/**
 * _fix - assigns value
 * @lineptr: hold pointer to output
 * @n: hold size of the input buffer
 * @ptr: buffer
 * @i: counter
 *
 * Return: Void
 */
void _fix(char **lineptr, size_t *n, char *ptr, size_t i)
{
	if (*lineptr == NULL || *n < i)
	{
		if (lineptr == NULL)
			free(lineptr);
		*lineptr = ptr;
		*n = i;
	}
	else
	{
		_strcpy(*lineptr, ptr);
		free(ptr);
	}
}

/**
 * _getline - function is used to read a stream.
 * @lineptr: hold pointer to output
 * @n: hold size of the input buffer
 * @stream: is the input file handle
 *
 * Return: pointer to the output string
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t i;
	ssize_t count, size;
	char *ptr, c;
	int fl;

	size = *n, i = 0;
	if (i == 0)
		fflush(stream);
	else
		return (-1);
	if (*n == 0)
		size = *n = 1024;
	ptr = malloc(sizeof(char) * size);
	if (ptr == NULL)
		return (-1);
	for (;;)
	{
		fl = read(STDIN_FILENO, &c, 1);
		if (fl == 0)
		{
			free(ptr);
			return (-1);
		}
		if (c == '\n')
			break;
		if (i >= size)
		{
			if (_realloc(ptr, i, i + 1) == NULL)
			{
				free(ptr);
				return (-1);
			}
		}
		ptr[i] = c;
		i++;
	}
	ptr[i] = '\0';
	_fix(lineptr, n, ptr, i);
	count = i, i = 0;
	return (count);
}
