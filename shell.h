#ifndef _SHELL__
#define _SHELL__

#define BUFSIZE 1024
#define TOKEN_BUFSIZE 128
#define TOKEN_DELIM " \t\r\n\a"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

/**
 * struct op - shell data for current session
 *
 * @av: argument vector
 * @cmd: input command
 * @env: env variables
 * @name: the program name
 * @exCo: exit value
 * @count: counts number of processes
 * @pid: pid of current process
 */
typedef struct op
{
	char **av;
	char *cmd;
	char **env;
	char *name;
	int exCo;
	int count;
	char *pid;
} op_t;

/**
 * struct new - struct data
 * @s: string address holder
 * @find: find builtin command
 */
typedef struct new
{
	char *s;
	int (*find)(op_t *obs);
} ph;

extern char **environ;

void start(op_t *obs, char **argv);
void unstart(op_t *obs);
void handle(int sig);
void entry(op_t *obs);

char *_getenv(char **_environ, const char *name);

int parse(op_t *obs, char *order);
int _exe(op_t *obs);

int (*find(char *str))(op_t *obs);
int exitfun(op_t *obs);
int envfun(op_t *obs);

void prompt(void);
char *_line(int *chr);
char **tokenize(char *s);
char *analyze_cmd(op_t *obs, char *cmd);
char *exp_variables(op_t *obs, char *s);

void write_err(op_t *obs, int status);

#endif
