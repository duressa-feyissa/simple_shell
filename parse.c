#include "main.h"

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

	fl = 0;
	obs->av = _strtok(order);
	if (obs->av == NULL)
	{
		return (0);
	}
	fl = _exe(obs);
	free(obs->av);
	return (fl);
}
