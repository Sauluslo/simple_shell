#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define DEL_DEF " \t\r\n\a"
#define EXIT_BUILT_IN "exit"
#define ENV_BUILT_IN "env"

void print_env(void);
int execute(char **);
char **split_line(char *, char *);
char *concat_command(char *, char *);
int execute2(char **argv);
char *src_command(char *farg);

extern char **environ;
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *str1, char *str2, char *res);

#endif
