#ifndef __STRING_H
#define __STRING_H

#include <unistd.h>
#include <stdlib.h>

char *_strdup(const char *s);
size_t _strlen(const char *s);
void *_memcpy(void *dest, const void *src, size_t n);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_itoa(int);
int _isdigit(char *str);
int _intlen(int n);

#endif
