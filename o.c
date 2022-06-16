#include "shell.h"

/**
 * repl - Read-Eval-Print-Loop for the shell
 *
 * @shell: shell data
 */
void repl(shell_t *shell)
{
	char *cmd;
	int chr, flag, isLoop, tcheck;

	tcheck = isatty(STDIN_FILENO);
	do {
		isLoop = 1;
		if (tcheck == 1)
			prompt();

		cmd = read_line(&chr);
		if (chr == -1)
		{
			free(cmd);
			if (tcheck == 1)
				write(STDOUT_FILENO, "\n", 2);
			return;
		}

		if (cmd == NULL)
			continue;

		flag = parse_command(shell, cmd);
		if (flag == EXIT_IND)
			isLoop = 0;
	} while (isLoop);
}
