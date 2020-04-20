#include "shell.h"
/**
 * main -function
 *
 * Return: Always successfull.
*/
int main(int argc, char **argv)
{
	int interative = isatty(STDIN_FILENO);
	int status = 0;
	size_t bufsize = 0;
	int count = 1;
	char *s = "$ ";
	(void) argc;

	do {
		char *line = NULL;

		if (interative == 1)
		{
			write_in(s);
		}
		if (getline(&line, &bufsize, stdin) == -1)
		{
			free(line);
			break;
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
				status = execute(tokens, argv[0], count);
			}
			else {
				status = 98;
			}
			free(tokens);
		}
		count++;
		free(line);
	} while (1);
	exit(status);
}
