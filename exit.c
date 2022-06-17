#include "shell.h"

/**
 * exitfun - exit function
 * @obs: shell data
 *
 * Return: 0 on success and otherwise another integer
 */
int exitfun(op_t *obs)
{
	int st, y;

	st = 0;
	if (obs->av[1] != NULL)
	{
		y = _isdigit(obs->av[1]);
		if (y == 0)
		{
			write_err(obs, 2);
			return (0);
		}
		st = _atoi(obs->av[1]);
		obs->exCo = st % 256;
	}

	return (2);
}
