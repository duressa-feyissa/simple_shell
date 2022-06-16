#include "shell.h"

/**
 * main - Main Entry
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char **argv)
{
	int pathv = 0, status = 1, isPath = 0;
	char *ptr = NULL, **cmds = NULL;
	op_t obs;

	_envStart(&obs);
	(void)argc;
	while (status)
	{
		errno = 0;
		ptr = _getcmd();
		if (ptr == NULL && errno == 0)
			return (0);
		if (ptr)
		{
			pathv++;
			cmds = _strtoken(ptr);
			if (cmds == NULL)
				free(ptr);
			isPath = valuePath(&cmds[0], environ);
			status = _forkfun(cmds, argv, environ, ptr, pathv, isPath, &obs);
			if (status == 200)
			{
				free(ptr);
				return (0);
			}
			if (isPath == 0)
				free(cmds[0]);
			free(cmds);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(status);
		}
		free(ptr);
	}
	unstart(&obs);
	return (obs.exCo);
}
