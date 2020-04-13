#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define TOKEN_DELIM " \t\r\n\a"

char **split_line(char *);

int main(int ac, char **av, char **env)
{
	char *line = NULL;
	size_t bufsize = 0;
	char **argv = NULL;
	(void)ac;
	(void)av;
	/*char *envp[] = {
		"PATH=/bin"
	};
	envp[0] = getenv("PATH");]*/
	/*extern char** environ;*/

	printf("$ ");
	while (1) {
		if (getline(&line, &bufsize, stdin) == -1) {
			return 0;
		} else {
			printf("%s", line);

			argv = split_line(line);
			/*execute*/
			if (execve(argv[0], argv, env) == -1)
			{
			perror("Error:");
			}
			printf("$ ");
		}
	}
}
/**
 *
 *
 *
 *
*/
char **split_line(char *line) {
	int pos = 0, bufsize = 64;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *word;

	word = strtok(line, TOKEN_DELIM);
	while (word != NULL) {
		printf(">word %d: %s\n", pos, word);
		tokens[pos] = word;
		pos++;
		word = strtok(NULL, TOKEN_DELIM);
	}
	tokens[pos] = NULL;
	
	return tokens;
}
