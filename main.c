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

	start(&obs, argv, env);
	signal(SIGINT, handle);
	entry(&obs);
	unstart(&obs);

	return (obs.exCo);
}
