#include "shell.h"

/**
 * exitfun - exit function
 * @obs: shell data
 *
 * Return: 0 on success and otherwise another integer
 */
int exitfun(op_t *obs)
{
	if (obs->argv[1] != NULL)
	{
		perror("Error");
		return (0);
	}
	obs->exCo = 0;
	return (200);
}
