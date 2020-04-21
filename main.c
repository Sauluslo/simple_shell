#include "shell.h"
/**
 * main -function
 * @argc: num arguments
 * @argv: arguments
 * @envp: environ.
 *
 * Return: Always successfull.
*/
int main(int argc, char **argv, char **envp)
{
	int status = 0;
	(void) argc;

	status = process(argv, envp);
	exit(status);
}
