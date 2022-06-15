#include "shell.h"

char *builtin[] = {"cd", "exit", "^D"};

int (*builtinFun[])(char **) = {&cdFun, &exitFun, &ctrld};

/**
 * num_builtins - size
 * Return: size
 */
int num_builtins(void)
{
	return (sizeof(builtin) / sizeof(char *));
}

/**
 * cdFun - builtin to change dirs
 * @args: List of args.
 * Return: 1 on success
 */
int cdFun(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 * exitFun - builtin to exit the shell
 * @args: List of args.
 * Return: Always returns 200, to terminate execution.
 */
int exitFun(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 * ctrld - builtin to handle "^D" call
 * @args: List of args.  Not examined.
 * Return: Always returns 0, to terminate execution.
 */
int ctrld(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 *_forkfun - The function that create a fork.
 *@cmd: Command and values path.
 *@av: Has the name of our program.
 *@env: Environment
 *@lineptr: Command line for the user.
 *@np: ID of proces.
 *@c: Checker add new test
 *Return: 0 success
 */
int _forkfun(char **cmd, char **av, char **env, char *lineptr, int np, int c)
{

	pid_t child;
	int status, i = 0;
	char *format = "%s: %d: %s: not found\n";

	if (cmd[0] == NULL)
		return (1);
	for (i = 0; i < num_builtins(); i++)
	{
		if (_strcmp(cmd[0], builtin[i]) == 0)
			return (builtinFun[i](cmd));
	}
	child = fork();
	if (child == 0)
	{
		if (execve(cmd[0], cmd, env) == -1)
		{
			fprintf(stderr, format, av[0], np, cmd[0]);
			if (!c)
				free(cmd[0]);
			free(cmd);
			free(lineptr);
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
