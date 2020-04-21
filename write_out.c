#include "shell.h"
/**
 * write_out - print in stdout.
 * @s: msg in out.
 *
 * Return: Always successful
*/
void write_out(char *s)
{
	int len = _strlen(s);

	write(STDOUT_FILENO, s, len);
}
