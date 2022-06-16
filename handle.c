#include "shell.h"

/**
 * handl_signint - Handle Ctrl + c call in prompt.
 *
 * @sig: Signal
 */
void handl_signint(int sig)
{
	(void) sig;
	write(STDOUT_FILENO, "\n#cisfun$ ", 11);
}
