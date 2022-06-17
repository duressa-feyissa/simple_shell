#include "shell.h"

/**
 * parse - parse the command input from stdin
 * @obs: shell data
 * @order: command read from stdin.
 *
 * Return: flag
 */
int parse(op_t *obs, char *order)
{
	int fl;
	int (*hold)(op_t *shell);

	fl = 0;
	if (!order)
		return (0);
        obs->cmd = order;
	obs->av = tokenize(order);
	if (obs->av == NULL)
	{
		free(obs->cmd);
		return (0);
	}

	hold = find(obs->av[0]);
	if (hold)
		fl = hold(obs);
	else
		fl = 1;

	if (fl == 1)
		fl = _exe(obs);

	free(obs->av);
	free(obs->cmd);
	(obs->count)++;

	return (fl);
}
