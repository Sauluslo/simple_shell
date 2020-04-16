#include "shell.h"
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

	pid = fork();
	if (pid == 0)
	{
		execute2(argv);
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
 * execute2 - launch the command
 * @argv: arguments
 *
 * Return: always successfull
*/
int execute2(char **argv)
{
	char **arguments = argv;
	struct stat st;
	char *fullpath_command = NULL;
	char *first_arg = arguments[0];

	if (stat(first_arg, &st) == 0)
	{
		fullpath_command = first_arg;
	}
	else
	{
		fullpath_command = src_command(first_arg);
	}
	if (fullpath_command != NULL)
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
/**
 * src_command - search command in the path
 * @farg: arguments
 *
 * Return: always successfull.
*/
char *src_command(char *farg)
{
	char **directories;
	char *directory;
	char *envpath = getenv("PATH");
	char *envpath_copy = malloc(_strlen(envpath) + 1);
	char *first_arg = farg;
	char *fullpath_command;
	int i = 0, command_found;
	struct stat st;

	_strcpy(envpath_copy, envpath);
	directories = split_line(envpath_copy, ":");
	directory = directories[i];
	while (directory != NULL)
	{
		fullpath_command = concat_command(directory, first_arg);
		if (fullpath_command == NULL)
		{
			return (NULL);
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
	if (command_found == 0)
		return (fullpath_command);
	else
		return (NULL);
}
