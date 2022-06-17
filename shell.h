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
#include <string.h>
#include <limits.h>

/**
 * struct op - shell data for current session
 *
 * @av: argument vector
 * @cmd: input command
 * @environ: env variables
 * @name: the program name
 * @exCo: exit value
 * @count: counts number of processes
 * @pid: pid of current process
 */
typedef struct op
{
	char **av;
	char *cmd;
	char **environ;
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

void handle(int sig);
void entry(op_t *obs);

char *_getdone(op_t *obs, const char *name);
char *_getenv(char **_environ, const char *name);

int parse(op_t *obs, char *order);
int _exe(op_t *obs);

int (*find(char *str))(op_t *obs);
int exitfun(op_t *obs);
int envfun(op_t *obs);
int h_unsetenv(op_t *obs);
int h_setenv(op_t *obs);
int _setenv(op_t *obs, char *name, char *value, int overwrite);
int _unsetenv(op_t *obs, const char *name);

void prompt(void);
char *_line(int *chr);
char **tokenize(char *s);

void write_err(op_t *obs, int status);

char *_strdup(const char *str);
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
size_t _strncmp(char *s1, char *s2, size_t n);
int _isdigit(char *c);
int _atoi(char *s);
char *_itoa(int n);
int _intlen(int n);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_realloc2(char **ptr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t count);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

#endif
