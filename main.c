#include "main.h"

/**
 * main - Main Entry
 * @argc: argument count
 * @argv: argument vector
 * @env: enviromental variable
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	op_t obs;
	(void)argc;
	(void)env;

	obs.av = NULL;
	obs.name = argv[0];
	entry(&obs);

	return (0);
}
