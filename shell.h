#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define DELIM " \t\n"
extern char **environ;

void freearray2D(char **array);
char *read_line(void);
char **tokenizer(char *l);
int _execute(char **com, char **arguv);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_getenv(char *variable);
char *_getpath(char *com);



#endif
