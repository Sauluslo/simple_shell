#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define TOKEN_DELIM " \t\r\n\a"

char **split_line(char *);
int launch(char **);
void print_env();
extern char** environ;

int main(int ac, char **av)
{
	char *line = NULL;
	size_t bufsize = 0;
	char **tokens = NULL;
	(void)ac;
	(void)av;
	/*char *envp[] = {
		(char *) "PATH=/bin", NULL
	};*/
	/*envp[0] = getenv("PATH");]*/
	/*extern char** environ;*/

	printf("$ ");
	while (1) {
		if (getline(&line, &bufsize, stdin) == -1) {
			return 0;
		} else {
			printf("%s", line);

			tokens = split_line(line);
			/*execute*/
			if (strcmp(tokens[0], "exit") == 0)
			{
				return (0);
			}
			else if (strcmp(tokens[0], "env") == 0)
			{
				print_env();
			}
			else
			{
				launch(tokens);
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
/**
 *
 *
 *
*/
int launch(char **argv)
{
	char *envp[] = { (char *) "PATH=/bin", NULL };
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0) {
		/* Child process */
		if (execve(argv[0], argv, envp) == -1) {
			perror("lsh");
		}
		exit(EXIT_FAILURE);
	} else if (pid < 0) {
		/* Error forking */
		perror("lsh");
	} else {
		/* Parent process */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return 1;
}

void print_env()
{
	/*char *command[] = {"/usr/bin/printenv"};
	launch(command);*/
	int i = 1;
	char *s = *environ;
	for (; s; i++) {
		printf("%s\n", s);
		s = *(environ+i);
	}
}
