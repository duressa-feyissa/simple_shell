#include "main.h"

/**
 * _exe - execute the command
 * @obs: shell data
 *
 * Return: Success of execution
 */
int _exe(op_t *obs)
{
	int i, sys;
	pid_t child_pid;
	char **argv;

	argv = obs->av;

	i = 0;
	while (argv[i])
		i++;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror(obs->name);
		return (1);
	}
	else if (child_pid == 0)
	{
		if (i != 1)
		{
			perror(obs->name);
			return (0);
		}
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(obs->name);
		}
	}
	else
	{
		do {
			waitpid(child_pid, &sys, WUNTRACED);
		} while (!WIFEXITED(sys) && !WIFSIGNALED(sys));
	}
	return (0);
}
