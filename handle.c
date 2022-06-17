#include "shell.h"

/**
 * handle - Handle Ctrl + c call in prompt.
 *
 * @sig: Signal
 * Return: Void
 */
void handle(int sig)
{
	(void) sig;
	write(STDOUT_FILENO, "\n#cisfun$ ", 11);
}
