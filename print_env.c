#include "shell.h"
/**
 * print_env - print env
 *
 * Return: Always successful
*/
void print_env(void)
{
	int i = 1;
	char *s = *environ;

	for (; s; i++)
	{
		write_out(s);
		s = *(environ + i);
	}
}
