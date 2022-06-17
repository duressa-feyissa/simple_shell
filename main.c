#include "shell.h"

/**
 * main - Main Entry
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char **argv)
{
	unsigned int i;
	op_t obs;
	(void)argc;

	obs.av = NULL;
	obs.cmd = NULL;
	obs.name = argv[0];
	obs.exCo = 0;
	obs.count = 1;
	obs.pid = _itoa(getpid());

	i = 0;
	while (environ[i])
		i++;
	obs.environ = malloc(sizeof(char *) * (i + 1));
	if (obs.environ == NULL)
	{
		write(STDERR_FILENO, "Error\n", 7);
	}
	else
	{
		i = 0;
		while (environ[i])
		{
			obs.environ[i] = _strdup(environ[i]);
			i++;
		}
		obs.environ[i] = NULL;
	}
	signal(SIGINT, handle);
	entry(&obs);

	free(obs.pid);
	for (i = 0; obs.environ[i]; i++)
	{
		free(obs.environ[i]);
	}
	free(obs.environ);

	return (obs.exCo);
}
