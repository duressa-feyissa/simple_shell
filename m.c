#include "shell.h"

/**
 *  prompt - prints the prompt
 */
void prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 10);
}
