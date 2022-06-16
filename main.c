#include "main.h"

/**
 * main - Main Entry
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char **argv)
{
	op_t obs;
	(void)argc;

	start(&obs, argv);
	signal(SIGINT, handle);
	entry(&obs);
	unstart(&obs);

	return (obs.exCo);
}
