#include "shell.h"
#include "util.h"

/**
 * parse_command - splits a string into an array
 *
 * @shell: shell data
 * @command: command input
 * Return: 0 on success otherwise 1 for error
 * or another integer
 */
int parse_command(shell_t *shell, char *command)
{
	int flag = 0;
	int (*handl)(shell_t *shell);

	command = analyze_cmd(shell, command);
	if (!command)
		return (0);

	shell->command = command;
	shell->argv = tokenize(command);
	if (shell->argv == NULL)
	{
		free(shell->command);
		return (0);
	}

	/* Check for builtins */
	handl = get_builtin_handl(shell->argv[0]);
	if (handl)
		flag = handl(shell);
	else
		flag = 1;

	if (flag == 1)
		flag = execute(shell);

	free(shell->argv);
	free(shell->command);

	(shell->count)++;

	return (flag); /* Success */
}
