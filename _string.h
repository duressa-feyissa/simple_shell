#ifndef __STRING_H
#define __STRING_H

#include <unistd.h>
#include <stdlib.h>

char *_strdup(char *str);
int _strlen(char *s);
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

#endif
