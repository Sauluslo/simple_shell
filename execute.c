#include "shell.h"
/**
 * execute - execute my progrman
 * @argv: arguments vector
 * @shell_name: hsh
 * @count: count error.
 * @envp: environ.
 *
 * Return: always successful
*/
int execute(char **argv, char *shell_name, int count, char **envp)
{
	pid_t pid;
	int child_status;
	char *fullcommand;

	fullcommand = execute1(argv, envp);
	if (fullcommand == NULL)
	{
		free(fullcommand);
		return (error_msg(count, argv, shell_name));
	}
	if (access(fullcommand, X_OK) == -1)
		return (126);
	argv[0] = fullcommand;
	pid = fork();
	if (pid == 0)
	{
		execute2(argv, envp);
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
	free(fullcommand);
	return (WEXITSTATUS(child_status));
}
/**
 * execute1 - launch the command
 * @argv: arguments
 * @envp: environ.
 *
 * Return: always successfull
*/
char *execute1(char **argv, char **envp)
{
	struct stat st;
	char *fullpath_command = NULL;
	char *first_arg = argv[0];

	if (stat(first_arg, &st) == 0)
	{
		fullpath_command = malloc(_strlen(first_arg) + 1 * sizeof(char));
		_strcpy(fullpath_command, first_arg);
	}
	else
	{
		fullpath_command = src_command(first_arg, envp);
	}
	return (fullpath_command);
}
/**
 * execute2 - src command and execute
 * @argv: arguments
 * @envp: environ
 *
 * Return: always successfull
*/
int execute2(char **argv, char **envp)
{
	if (argv[0] != NULL)
	{
		if (execve(argv[0], argv, envp) == -1)
		{
			perror("Error");
		}
	}
	exit(EXIT_FAILURE);
}
/**
 * src_command - search command in the path
 * @farg: arguments
 * @envp: environ
 *
 * Return: always successfull.
*/
char *src_command(char *farg, char **envp)
{
	char **directories;
	char *directory;
	char *envpath = _getenv("PATH", envp);
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
			free(fullpath_command);
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
	free(envpath);
	if (command_found == 0)
		return (fullpath_command);
	else
		return (NULL);
}
