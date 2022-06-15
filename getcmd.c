#include "shell.h"

/**
 * _getcmd - read command from stream
 *
 * Return: command
 */
char *_getcmd(void)
{
	char *lineptr = NULL;
	size_t ch = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "#cisfun$ ", 9);

	if (getline(&lineptr, &ch, stdin) == -1)
	{
		free(lineptr);
		return (NULL);
	}
	return (lineptr);
}
