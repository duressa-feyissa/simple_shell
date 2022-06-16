#include "shell.h"
#include "util.h"

/**
 * assign_lineptr - assigns values to the lineptr
 *
 * @lineptr: output pointer
 * @n: the maximum number of char to read
 * @buffer: read string
 * @count: number of char actually read
 *
 * Return: pointer to the output string
 */
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t count)
{
	if (*lineptr == NULL || *n < count)
	{
		if (!lineptr)
			free(lineptr);
		*lineptr = buffer;
		*n = count;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * _getline - reads an entire line from stream, store the
 * address of the buffer containing the text int *lineptr. Can only
 * be used once at a time.
 *
 * @lineptr: output pointer
 * @n: the maximum number of char to read
 * @stream: the stream
 *
 * Return: pointer to the output string
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t count;
	ssize_t count_cp, bufsize = *n;
	char *buffer = NULL, ch;
	int loop, flag;

	if (count == 0) /* _getline is free */
		fflush(stream); /* clear stream */
	else /* _getline is already in used */
		return (-1);

	if (*n == 0) /* use default BUFSIZE */
		bufsize = *n = BUFSIZE;

	loop = 1, count = 0;
	buffer = malloc(sizeof(char) * bufsize);
	if (!buffer)
		return (-1);

	while (loop)
	{
		flag = read(STDIN_FILENO, &ch, 1);
		if (flag == 0) /* EOF */
		{
			free(buffer), count = 0; /* so _getline can be used again */
			return (-1);
		}
		if (ch == '\n') /* is newline? */
			break;
		if (count >= bufsize) /* more than bufsize? */
			if (_realloc(buffer, count, count + 1) == NULL)
			{
				free(buffer);
				return (-1);
			}
		buffer[count++] = ch;
	}
	buffer[count] = '\0';
	assign_lineptr(lineptr, n, buffer, count);
	count_cp = count, count = 0; /* so _getline can be used again */
	return (count_cp);
}
