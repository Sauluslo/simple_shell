#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define DEL_DEF " \t\r\n\a"
#define EXIT_BUILT_IN "exit"
#define ENV_BUILT_IN "env"

void print_env(char **envp);
int execute(char **, char *shell_name, int count, char **envp);
char **split_line(char *, char *);
char *concat_command(char *, char *);
int execute2(char **argv, char **envp);
char *execute1(char **argv, char **envp);
char *src_command(char *farg, char **envp);
char *_getenv(char *key, char **envp);
char *_getvalue(char *keyvalue, char *key);
void write_error(char *s);
void write_out(char *s);
void write_in(char *s);
int process(char **argv, char **envp);
int error_msg(int count, char **argv, char *shell_name);

/*extern char **environ;*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int access(const char *pathname, int mode);
char *_strcat(char *str1, char *str2, char *res);
void swap(char *xp, char *yp);
char *reverse(char str[], int length);
char *_itoa(int num, char *str, int base);

#endif
