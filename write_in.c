#include "shell.h"
/**
 * write_ot - print in stdout.
 * @s: msg in out.
 *
 * Return: Always successful
*/
void write_in(char *s)
{
	int len = _strlen(s);

	write(STDIN_FILENO, s, len);
}
