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
int _forkfun(char **cmd, char **av, char **env, char *lineptr, int np, int c);

/** Builtin **/
int cdFun(char **args);
int exitFun(char **args);
int ctrld(char **args);

#endif
