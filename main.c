#include "shell.h"
/**
 * main -function
 *
 * Return: Always successfull.
*/
int main(void)
{
	int interative = isatty(STDIN_FILENO);
	int status = 0;
	size_t bufsize = 0;

	do {
		char *line = NULL;

		if (interative == 1)
			printf("$ ");
		if (getline(&line, &bufsize, stdin) == -1)
		{
			free(line);
			return (status);
		}
		else
		{
			char **tokens = split_line(line, DEL_DEF);
			char *first_token = tokens[0];

			if (_strcmp(first_token, EXIT_BUILT_IN) == 0)
			{
				free(line);
				free(tokens);
				return (status);
			}
			else if (_strcmp(first_token, ENV_BUILT_IN) == 0)
			{
				print_env();
			}
			else if (tokens[0] != NULL)
			{
				status = execute(tokens);
			}
			free(tokens);
		}
		free(line);
	} while (1);
	exit(status);
}
