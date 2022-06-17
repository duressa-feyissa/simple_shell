#include "shell.h"

/**
 * entry - Print-Loop for the shell
 *
 * @obs: shell data
 * Return: Void
 */
void entry(op_t *obs)
{
	char *cmd;
	int check, loop, x, fl;


	check = isatty(STDIN_FILENO);
	do {
		loop = 1;
		if (check == 1)
			prompt();

		cmd = _line(&x);
		if (x == -1)
		{
			free(cmd);
			if (check == 1)
				write(STDOUT_FILENO, "\n", 2);
			return;
		}

		if (cmd == NULL)
			continue;

		fl = parse(obs, cmd);
		if (fl == 2)
			loop = 0;
	} while (loop);
}
