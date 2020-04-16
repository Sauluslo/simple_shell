#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "shell.h"

#define DEL_DEF " \t\r\n\a"
#define EXIT_BUILT_IN "exit"
#define ENV_BUILT_IN "env"

void print_env(void);
int execute(char **);
char **split_line(char *, char *);
char *concat_command(char *, char *);
/**
 * main - function
 *
 * Return: always successful
*/
int main(void)
{
	int status = 0;
	size_t bufsize = 0;

	do {
		printf("$ ");
		char *line = NULL;
		if (getline(&line, &bufsize, stdin) == -1)
		{
			free(line);
			return (0);
		}
		else
		{
			char **tokens = split_line(line, DEL_DEF);
			char *first_token = tokens[0];
			if (_strcmp(first_token, EXIT_BUILT_IN) == 0)
			{
				free(line);
				free(tokens);
				return (0);
			}
			else if (_strcmp(first_token, ENV_BUILT_IN) == 0)
			{
				print_env();
			}
			else
			{
				status = execute(tokens);
			}
			free(tokens);
		}
		free(line);
	} while (1);

	exit(status);
}
/**
 * split_line - use strtok
 * @line: command
 * @delim: delimitadores
 *
 * Return: always successful.
*/
char **split_line(char *line, char *delim)
{
	int pos = 0, tokens_len = 1;
	char *word = NULL;
	char **tokens = NULL;
	char *line_copy = malloc((_strlen(line) + 1) * sizeof(char));

	_strcpy(line_copy, line);
	word = strtok(line_copy, delim);
	while (word != NULL) {
		tokens_len++;
		word = strtok(NULL, delim);
	}

	tokens = malloc(tokens_len * sizeof(char *));
	word = strtok(line, delim);
	while (word != NULL) {
		tokens[pos++] = word;
		word = strtok(NULL, delim);
	}
	free(word);
	free(line_copy);
	return (tokens);
}
/**
 * execute - execute my progrman
 * @argv: arguments vector
 *
 * Return: always successful
*/
int execute(char **argv)
{
	pid_t pid;
	int child_status;
	char **arguments = argv;

	pid = fork();
	if (pid == 0)
	{
		int i = 0, command_found = 0;
		struct stat st;
		char *fullpath_command = NULL;
		char *first_arg = arguments[0];

		command_found = stat(first_arg, &st);
		if (command_found == 0)
		{
			fullpath_command = first_arg;
		}
		else
		{
			char **directories;
			char *directory;
			char *envpath = getenv("PATH");
			char *envpath_copy = malloc(_strlen(envpath) + 1);

			_strcpy(envpath_copy, envpath);
			directories = split_line(envpath_copy, ":");
			directory = directories[i];
			while (directory != NULL)
			{
				fullpath_command = concat_command(directory, first_arg);
				if (fullpath_command == NULL)
				{
					return (EXIT_FAILURE);
				}
				command_found = stat(fullpath_command, &st);
				if (command_found == 0)
				{
					break;
				}
				directory = directories[++i];
				free(fullpath_command);
			}
			free(directories);
			free(envpath_copy);
		}
		if (command_found == 0)
		{
			char **envp = environ;
			if (execve(fullpath_command, arguments, envp) == -1)
			{
				perror("Error");
			}
		}
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Error");
	}
	else
	{
		do {
			waitpid(pid, &child_status, WUNTRACED);
		} while (!WIFEXITED(child_status) && !WIFSIGNALED(child_status));
	}
	return (child_status);
}
/**
 * print_env - print env
 *
 * Return: Always successful
*/
void print_env(void)
{
	int i = 1;
	char *s = *environ;

	for (; s; i++)
	{
		printf("%s\n", s);
		s = *(environ + i);
	}
}
/**
 * concat_command - concatena el path con el comando ingresado
 * @path: pathname
 * @command: comando ingresado.
 *
 * Return: Always successful
*/
char *concat_command(char *path, char *command)
{
	char *buffer = NULL;

	return (_strcat(path, command, buffer));
}
