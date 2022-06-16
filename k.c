#include "shell.h"
#include "_string.h"

/**
 * initialize - setup shell variables
 *
 * @shell: shell data
 * @av: argument vector for name
 */
void initialize(shell_t *shell, char **av)
{
	unsigned int i;

	shell->argv = NULL;
	shell->command = NULL;
	shell->exitcode = 0;
	shell->count = 1;
	shell->name = av[0];
	shell->pid = _itoa(getpid());

	for (i = 0; environ[i]; i++)
		;

	/* Make copy of the environs */
	shell->environ = malloc(sizeof(char *) * (i + 1));
	if (shell->environ == NULL)
	{
		write(STDERR_FILENO, "Error\n", 7);
		return;
	}
	for (i = 0; environ[i]; i++)
		shell->environ[i] = _strdup(environ[i]);
	shell->environ[i] = NULL;
}

/**
 * uninitialize - frees shell data
 *
 * @shell: shell data
 */
void uninitialize(shell_t *shell)
{
	unsigned int i;

	free(shell->pid);

	for (i = 0; shell->environ[i]; i++)
		free(shell->environ[i]);
	free(shell->environ);
}
