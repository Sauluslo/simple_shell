#include "shell.h"
/**
 * main -function
 *
 * Return: Always successfull.
*/
int main(void)
{
	int status = 0;
	size_t bufsize = 0;

	do {
		char *line = NULL;
		printf("$ ");

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
