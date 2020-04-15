#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "shell.h"

#define DEL_DEF " \t\r\n\a"

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
	size_t bufsize = 0;
	int status;

	printf("$ ");
	while (1)
	{
		char *line = NULL;

		if (getline(&line, &bufsize, stdin) == -1)
		{
			return (0);
		}
		else
		{
			char **tokens = split_line(line, DEL_DEF);
			if (_strcmp(tokens[0], "exit") == 0)
			{
				free(tokens);
				free(line);
				return (0);
			}
			else if (_strcmp(tokens[0], "env") == 0)
			{
				print_env();
			}
			else
			{
				status = execute(tokens);
			}
			printf("$ ");
			free(tokens);
		}
		free(line);
	}
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
	int pos = 0, bufsize = 1;
	char **tokens = malloc((bufsize + 1) * sizeof(char*));
	char *word;

	word = strtok(line, delim);
	while (word != NULL)
	{
		if (pos >= bufsize)
		{
			bufsize++;
			tokens = realloc(tokens, (bufsize + 1) * sizeof(char*));
		}
		tokens[pos] = word;
		pos++;
		word = strtok(NULL, delim);
	}
	tokens[pos] = NULL;

	if (pos < bufsize)
	{
		tokens = realloc(tokens, pos * sizeof(char*));
	}	
	return (tokens);
}
/**
 * execute - execute my progrman
 * @argv: vectores
 *
 * Return: always successful
*/
int execute(char **argv)
{
	pid_t pid;
	int child_status;

	pid = fork();
	if (pid == 0)
	{
		int i = 0;
		struct stat st;
		int command_found;
		char *fullpath_command = NULL;
		/*char **directories;
		char *directory;
		char *envpath = getenv("PATH");
		char *envpath_copy = malloc(_strlen(envpath) + 1);

		_strcpy(envpath_copy, envpath);
		directories = split_line(envpath_copy, ":");
		directory = directories[i];*/

		command_found = stat(argv[0], &st);
		if (command_found == 0)
		{
			fullpath_command = argv[0];
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
				fullpath_command = concat_command(directory, argv[0]);
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
			if (execve(fullpath_command, argv, environ) == -1)
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
