#include "shell.h"

/**
 * exitfun - exit function
 * @obs: shell data
 *
 * Return: 0 on success and otherwise another integer
 */
int exitfun(op_t *obs)
{
	obs->exCo = 0;
	return (200);
}
