#include "shell.h"
/**
 * print_env - print env
 * @envp: environ
 *
 * Return: Always successful
*/
void print_env(char **envp)
{
	int i = 1;
	char *s = *envp;

	for (; s; i++)
	{
		char *res = NULL;
		char *line = _strcat(s, "\n", res);

		write_out(line);
		s = *(envp + i);
		free(line);
	}
}
