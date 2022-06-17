#include "shell.h"

/**
 * prompt - prints the prompt
 *
 * Retrun: Void
 */
void prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 10);
}
