#include "shell.h"
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
	while (word != NULL)
	{
		tokens_len++;
		word = strtok(NULL, delim);
	}

	tokens = malloc(tokens_len * sizeof(char *));
	word = strtok(line, delim);
	while (word != NULL)
	{
		tokens[pos++] = word;
		word = strtok(NULL, delim);
	}
	tokens[pos] = NULL;
	free(word);
	free(line_copy);
	return (tokens);
}
