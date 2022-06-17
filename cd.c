#include "shell.h"

/**
 * cd_one - cd - commnad executor
 * @obs: shell data
 *
 * Return: on success 0 otherwise -1
 */
int cd_one(op_t *obs)
{
	char *new, *now, *str, ch1[128];
	int x;

	new = _getdone(obs, "OLDPWD");
	if (new == NULL)
	{
		write_err(obs, 2);
		return (-1);
	}
	else
	{
		x = chdir(new);
		if (x == -1)
			write_err(obs, 2);
		else
		{
			str = getcwd(ch1, 128);
			_setenv(obs, "PWD", str, 1);
			now = _getdone(obs, "PWD");
			write(STDOUT_FILENO, new, _strlen(now));
			write(STDOUT_FILENO, "\n", 1);
			free(now);
		}
	}
	free(new);
	return (0);
}

/**
 * cdfun - cd commnad executor
 * @obs: shell data
 *
 * Return: on success 0
 */
int cdfun(op_t *obs)
{
	int ac;
	char **av, ch2[128];
	char *home, *ptr, *ptr1, ch[128];

	ac = 0;
	av = obs->av;
	while (av[ac])
		ac++;

	if (ac > 2)
	{
		write_err(obs, 2);
	}

	ptr = getcwd(ch, 128);
	if (ac == 1 || (ac == 2 && (strcmp(av[1], "~") == 0)))
	{
		home = _getdone(obs, "HOME");
		if (chdir(home) == -1)
			 write_err(obs, 2);
		free(home);
	}
	else if (ac == 2 && (strcmp(av[1], "-") == 0))
	{
		if (cd_one(obs) == -1)
			return (0);
	}
	else
	{
		if (chdir(av[1]) == -1)
		       write_err(obs, 2);
	}
	_setenv(obs, "OLDPWD", ptr, 1);
	ptr1 = getcwd(ch2, 128);
	_setenv(obs, "PWD", ptr1, 1);
	return (0);
}
