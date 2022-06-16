#include "shell.h"

/**
 * main - Runs the shell
 * @ac: argument count
 * @av: argument vector
 * Return: 0
 */
int main(int ac, char **av)
{
	shell_t shell;
	(void) ac;

	initialize(&shell, av);
	signal(SIGINT, handl_signint);
	repl(&shell);
	uninitialize(&shell);

	return (shell.exitcode);
}
