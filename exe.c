#include "shell.h"

/**
 *_forkfun - The function that create a fork.
 *@cmd: Command and values path.
 *@av: Has the name of our program.
 *@en: Environment
 *@l: Command line for the user.
 *@p: ID of proces.
 *@c: Checker add new test
 *@o: shell data
 *Return: 0 success
 */
int _forkfun(char **cmd, char **av, char **en, char *l, int p, int c, op_t *o)
{
	pid_t child;
	int status;
	int (*hold)(op_t *shell);

	(void)en;
	o->argv = cmd;
	o->count = p;
	if (cmd[0] == NULL)
		return (1);
	hold = find(cmd[0]);
	if (hold)
		return (hold(o));
	child = fork();
	if (child == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(av[0]);
			if (!c)
				free(cmd[0]);
			free(cmd);
			free(l);
			exit(errno);
		}
	}
	else
	{
		do {
			waitpid(child, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		return (status);
	}
	return (0);
}
