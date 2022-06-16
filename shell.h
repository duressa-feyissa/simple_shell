#ifndef _SHELL_
#define _SHELL_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

/**
 * struct op - shell data for current session
 *
 * @argv: argument vector
 * @cmd: input command
 * @envn: env variables
 * @name: ______
 * @exCo: exit value
 * @count: number of proess
 */
typedef struct op
{
	char **argv;
	char **envn;
	char **cmd;
	char *name;
	int exCo;
	int count;
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

/** String Handler**/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
size_t _strncmp(char *s1, char *s2, size_t n);
int _isdigit(char *c);
int _atoi(char *s);

char *_getcmd(void);
char *_getPath(char **env);
void _getenv(char **env);
char **_strtoken(char *str);
int valuePath(char **av, char **env);
int _forkfun(char **cmd, char **av, char **en, char *l, int p, int c, op_t *o);

/** Builtin **/
int (*find(char *str))(op_t *obs);
int exitfun(op_t *obs);
int envfun(op_t *obs);
int ctrld(op_t *obs);

/** Memory **/
char *_strdup(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_realloc2(char **ptr, unsigned int old_size, unsigned int new_size);
void *_memcpy(void *dest, const void *src, size_t n);

/** Getline **/
void _fix(char **lineptr, size_t *n, char *ptr, size_t i);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

#endif
